#include <chrono>
#include <iostream>
#include <random>
#include <string>

#include "sum_functions.h"
#include "test_sum_functions.h"
#include "utils.h"

int main() {
    /* set up */
    Utils::Setup();
    std::vector<int> values = Sum::SourceToVec("test/arr.txt");

    /* testing */
    std::cout << "test #1: SourceToVec - ";
    Test::SourceToVec();
    std::cout << "passed\n";
    std::cout << "\n";

    /* performance analysis */
    constexpr size_t num_threads = 5;

    
    auto t1 = std::chrono::high_resolution_clock::now();
    int seqSumTotal = Sum::SequentialSum(values);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto seqTime = t2 - t1;

    t1 = std::chrono::high_resolution_clock::now();
    int multThreadTotal = Sum::MultiThreadedSum(values, num_threads);
    t2 = std::chrono::high_resolution_clock::now();
    auto multTime = t2 - t1;

    assert(seqSumTotal == multThreadTotal);

    std::cout << "SequentialSum() took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(seqTime).count()
              << " milliseconds\n";

    std::cout << "MultiThreadedSum() took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(multTime).count()
              << " milliseconds\n";


    /*
    std::cout << "total (sequential) - " << seqSumTotal << '\n';
    std::cout << "total (multithreaded) - " << multThreadTotal << '\n';
    */

    return 0;
}
