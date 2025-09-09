/*
 * HEADER-ONLY TESTING FILE
 */

#ifndef TEST_SUM_FUNCTIONS_H
#define TEST_SUM_FUNCTIONS_H

#include <cassert>
#include <cmath>
#include <chrono>
#include <random>
#include <string>
#include <fstream>
#include <string>

#include "sum.h"
#include "utils.h"

class Test {
public:
    /*
     * @brief tests converting file content into a vector
     */
    static inline void SourceToVec() {
        Sum sum;
        std::vector<int> arr = sum.SourceToVec(Utils::GetFilePath());
        assert(arr.size() == Utils::GetLines());
    }
};

#endif
