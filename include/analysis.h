#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <chrono>
#include "sum.h"

class Analysis {
public:
    static void VaryingNumberOfThreads() {
        unsigned int max_num_threads = std::thread::hardware_concurrency();
        std::vector<int> values = Sum::SourceToVec("../src/test/arr.txt");
        for (size_t num_threads {0}; num_threads < max_num_threads; ++num_threads) {

            auto start = std::chrono::high_resolution_clock::now();
            Sum::MultiThreadedSum(values, num_threads);
            auto end = std::chrono::high_resolution_clock::now();
            auto diff = end - start;

            namespace time = std::chrono;
            auto milli = std::chrono::duration_cast<time::milliseconds>(diff).count();
            std::cout << "num_threads(" << num_threads << ") ";
            std::cout << "time: " << milli << " ms\n";
        }
    }
};

#endif

