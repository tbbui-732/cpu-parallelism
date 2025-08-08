/*
 * HEADER-ONLY FILE FOR TESTING!
 */

#include <cmath>
#include <chrono>
#include <random>
#include <string>
#include <fstream>
#include <string>

#include "sum_functions.h"

class Test {
public:
    unsigned int seed;
    unsigned int wrap;
    size_t lines;
    std::string filename;

    Test() {
        this->seed      = std::chrono::system_clock::now()
                            .time_since_epoch()
                            .count();
        this->wrap      = static_cast<int>(std::pow(2, 15));
        this->lines     = static_cast<size_t>(std::pow(2, 10));
        this->filename  = "test/arr.txt";
    }

    inline void TestSourceToVec() {
        // create a file containing randomized values
        std::ofstream outfile(filename);
        if (!outfile.is_open()) {
            std::cout << "unable to open '" << filename << "'\n";
            return;
        }
        std::string content = GenerateContent();
        outfile.write(content.c_str(), content.size());
        outfile.close();

        // [testing] convert file to array
        Sum sum;
        std::vector<int> arr = sum.SourceToVec(filename);
        std::cout << "printing out source content";
        for (int val : arr) {
            std::cout << val << '\n';
        }
    }

private:
    inline std::string GenerateContent() {
        std::minstd_rand0 rand(seed);
        std::string content;
        for (size_t i{0}; i < lines; ++i) {
            auto num = rand() % wrap;
            content += std::to_string(num) + '\n';
        }
        return content;
    }
};
