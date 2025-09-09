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
        std::minstd_rand0 rand(seed);
        wrap = 1u << 9;
        lines = 1u << 22; // over 4mil
        directory = "test/";
        file = "arr.txt";
        if (!fs::exists(directory)) {
            fs::create_directory(directory);
        }
        GenerateContent();
    }
    static inline size_t GetLines() {
        return lines;
    }
    static inline std::string GetFilePath() {
        return (directory.string() + file);
    }
private:
    /*
     * @brief generates a list of random numbers and stores them at
     * the specified file directory
     */
    static inline unsigned int seed;
    static inline unsigned int wrap;
    static inline size_t lines;
    static inline fs::path directory;
    static inline std::string file;

    static inline void GenerateContent() {
        const std::string completePath = directory.string() + file;
        std::ofstream outfile(completePath, std::ofstream::out);
        if (!outfile.is_open()) {
            std::cout << "unable to open '" << completePath << "'\n";
            return;
        }
        for (size_t i{0}; i < lines; ++i) {
            outfile << rand() % wrap << '\n';
        }
        outfile.close();
    }
};

#endif
