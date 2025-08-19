#include "sum_functions.h"

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <functional>
#include <vector>
#include <sstream>
#include <thread>
#include <numeric>

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

/* TODO: rewrite this section using a tree-reduction algorithm */
int Sum::MultiThreadedSum(
    const std::vector<int>& values,
    const size_t num_threads
) {
    if (values.empty()) return 0;
    if (num_threads == 0) num_threads = 1; // should have at least a single
                                           // working thread
    
    num_threads = std::min(num_threads, values.size());

    // partial thread results are placed in partials[thread_id]
    std::vector<int> partials(num_threads, 0);

    // worker function
    auto worker = [&](const size_t thread_id) {
        // TODO: ...
        // split work evenly
        // compute partial sum and store it
        // sync threads before performing reduction
        // perform tree reduction
    };

    // run threads
    std::vector<std::thread> threads;
    threads.reserve(num_threads);
    for (size_t thread_id{0}; thread_id < num_threads; ++thread_id)
        threads.emplace_back(worker, thread_id);
    for (auto& thread : threads)
        thread.join();

    // final result in partial beginning
    return partials[0];
}
