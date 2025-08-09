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
    int total = Sum::SequentialSum(values);
    std::cout << "total (sequential) - " << total << '\n';

    total = Sum::MultiThreadedSum(values);
    std::cout << "total (multithreaded) - " << total << '\n';

    return 0;
}
