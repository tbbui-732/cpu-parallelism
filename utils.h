/*
 * HEADER-ONLY UTILITY FILE
 */

#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <filesystem>
#include <fstream>
#include <random>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class Utils {
public:
    static inline void Setup() {
        seed = static_cast<unsigned int>(
            std::chrono::system_clock::now().time_since_epoch().count()
        );
        wrap = 1u << 15;
        lines = 1u << 22; // over 4mil
        filepath = "test/arr.txt";
        GenerateContent();
    }

    static inline unsigned int GetSeed() { return seed; }
    static inline unsigned int GetWrap() { return wrap; }
    static inline size_t GetLines() { return lines; }
    static inline std::string GetFilePath() { return filepath; }
private:
    /*
     * @brief generates a list of random numbers and stores them at
     * a specified file path
     */
    static inline unsigned int seed;
    static inline unsigned int wrap;
    static inline size_t lines;
    static inline std::string filepath;

    static inline void GenerateContent() {
        std::minstd_rand0 rand(seed);
        std::ofstream outfile(filepath);
        if (!outfile.is_open()) {
            std::cout << "unable to open '" << filepath << "'\n";
            return;
        }
        for (size_t i{0}; i < lines; ++i) {
            outfile << rand() % wrap << '\n';
        }
        outfile.close();
    }
};

#endif
