#include "sum.h"

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <functional>
#include <vector>
#include <sstream>
#include <thread>
#include <numeric>
#include <barrier>
#include <cstdint>

std::vector<int> Sum::SourceToVec(const std::string& source) {
    std::vector<int> result;
    std::ifstream stream(source);
    if (!stream) {
        std::cout << "failed to initialize input file stream\n";
        return result; // empty vector on failure
    }
    for (std::string buffer; std::getline(stream, buffer);) {
        int conv = std::stoi(buffer);
        result.push_back(conv);
    }
    stream.close();
    return result;
}

std::int64_t Sum::SequentialSum(const std::vector<int>& values) {
    int result = 0;
    for (const int value : values) {
        result += value;
    }
    return result;
}

std::int64_t Sum::MultiThreadedSum(
    const std::vector<int>& values,
    size_t num_threads
) {
    if (values.empty())
        return 0;
    if (num_threads == 0)
        num_threads = 1;
    num_threads = std::min(num_threads, values.size());

    // determines amount of work each thread does
    const size_t volume = values.size();
    const size_t chunk = volume / num_threads;

    // each worker-thread sums a "chunk" of values
    // and places the partial result into partials[thread_id]
    std::vector<std::int64_t> partials(num_threads, 0);
    std::barrier sync_point(static_cast<std::ptrdiff_t>(num_threads));

    auto ThreadSum = [&](const size_t thread_id) {
        size_t start = thread_id * chunk;
        size_t end = start + chunk;
        if (thread_id == num_threads - 1) {
            // last thread *might* do more work...
            end = volume;
        }
        int partial = 0;
        for (size_t i = start; i < end; ++i) {
            partial += values[i];
        }
        partials[thread_id] = partial;

        // threads in reduction-tree must work on the same level!!!
        sync_point.arrive_and_wait();

        // tree-reduction algorithm
        // sums up the "partner" of the current thread
        for (size_t offset = 1; offset < num_threads; offset <<= 1) {
            // determines if current thread has a partner
            if ((thread_id % (2 * offset) == 0)) {
                size_t partner = thread_id + offset;
                if (partner < num_threads) {
                    partials[thread_id] += partials[partner];
                }
            }
            // wait for this level to finish
            sync_point.arrive_and_wait();
        }
    };

    // create and run threads
    std::vector<std::thread> threads;
    for (size_t thread_id = 0; thread_id < num_threads; ++thread_id) {
        threads.emplace_back(ThreadSum, thread_id);
    }
    for (auto& th : threads) th.join();
    return partials[0];
}
