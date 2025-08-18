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
    std::vector<int> partial(num_threads, 0);
    // worker function

    // create threads
    std::vector<std::thread> threads;
    threads.reserve(num_threads);
    for (size_t thread_id{0}; thread_id < num_threads; ++thread_id) {
        threads.emplace_back(worker, thread_id);
    }
    for (auto& thread : threads) {
        thread.join();
    }

    // final result in partial beginning
    return partial[0];
}
