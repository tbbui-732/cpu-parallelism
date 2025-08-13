#include "sum_functions.h"

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <functional>
#include <vector>
#include <sstream>
#include <thread>

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

int Sum::SequentialSum(const std::vector<int> values) {
    int result = 0;
    for (const int value : values) {
        result += value;
    }
    return result;
}

int Sum::MultiThreadedSum(
    const std::vector<int>& values,
    const size_t thread_count
) {
    const int width = values.size() / thread_count;
    std::vector<int> thread_results;
    thread_results.reserve(thread_count);

    // range based lambda sum function that updates @thread_results
    auto ThreadSum = [&](size_t start, size_t end, size_t thread) -> void {
        int result = 0;
        for (size_t i{start}; i < end; ++i)
            result += values[i];
        // placing at a specific @thread ensures thread-safety
        thread_results[thread] = result;
    };

    // create @thread_count number of threads
    std::vector<std::thread> threads;
    threads.reserve(thread_count);

    for (size_t thread = 0; thread < thread_count; ++thread) {
        size_t start = width * thread;
        size_t end = (thread == thread_count - 1) ?
                        values.size() : (width * thread) + width;
        threads.emplace_back(ThreadSum, start, end, thread);
    }

    // run all threads
    for (auto& t : threads) t.join();

    // TODO: tree-reduction for very large @thread_counts (?)
    // this might be overkill for <100 threads 
    constexpr unsigned int many_threads = 100; // arbitrary value
    if (thread_count >= many_threads) {
        // TODO: perform tree-reduction
        return 0; // placeholder...
    } else {
        int result = 0;
        for (const int val : thread_results) {
            result += val;
        }
    }

    return result;
}
