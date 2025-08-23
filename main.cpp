#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <cstdint>

#include "sum_functions.h"
#include "test_sum_functions.h"
#include "utils.h"

int main() {
    /* set up */
    Utils::Setup();
    std::vector<int> values = Sum::SourceToVec("test/arr.txt");

    /* testing */
    Test::SourceToVec();

    /* performance analysis */
    const unsigned int num_threads = std::thread::hardware_concurrency();

    auto t1 = std::chrono::high_resolution_clock::now();
    std::int64_t seqSumTotal = Sum::SequentialSum(values);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto seqTime = t2 - t1;

    t1 = std::chrono::high_resolution_clock::now();
    std::int64_t multThreadTotal = Sum::MultiThreadedSum(values, num_threads);
    t2 = std::chrono::high_resolution_clock::now();
    auto multTime = t2 - t1;

    t1 = std::chrono::high_resolution_clock::now();
    std::int64_t sample = std::accumulate(values.begin(), values.end(), 0);
    t2 = std::chrono::high_resolution_clock::now();
    auto accumTime = t2 - t1;

    assert(seqSumTotal == sample); // tested against a standard function
    assert(seqSumTotal == multThreadTotal);

    namespace milliseconds = std::chrono::milliseconds;
    std::cout 
        << "std::accumulate() ran in "
        << std::chrono::duration_cast<milliseconds>(accumTime).count()
        << " milliseconds\n";

    std::cout 
        << "SequentialSum() took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(seqTime).count()
        << " milliseconds\n";

    std::cout 
        << "MultiThreadedSum() took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(multTime).count()
        << " milliseconds\n";

    /*
     * Uncomment to see values.
     * NOTE: expect wrapping due to very large values
    std::cout << "total (sequential) - " << seqSumTotal << '\n';
    std::cout << "total (multithreaded) - " << multThreadTotal << '\n';
    */

    return 0;
}
