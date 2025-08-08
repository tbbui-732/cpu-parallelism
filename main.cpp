#include <chrono>
#include <iostream>
#include <random>
#include <string>

#include "sum_functions.h"
#include "test_sum_functions.h"

int main() {
    Test test;

    std::cout << "test #1: SourceToVec - ";
    test.TestSourceToVec();
    std::cout << "passed\n";

    return 0;
}
