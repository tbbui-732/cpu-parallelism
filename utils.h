/*
 * HEADER-ONLY UTILITY FILE
 */

#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
    static inline void Setup() {
        seed      = std::chrono::system_clock::now()
                      .time_since_epoch()
                      .count();
        wrap      = static_cast<int>(std::pow(2, 15));
        lines     = static_cast<size_t>(std::pow(2, 22)); // over 4mil
        filepath  = "test/arr.txt";
        GenerateContent();
    }

    static inline unsigned int GetSeed() {
        return seed;
    }

    static inline unsigned int GetWrap() {
        return wrap;
    }

    static inline size_t GetLines() {
        return lines;
    }

    static inline std::string GetFilepath() {
        return filepath;
    }
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

        /* TODO: write content diredctly instead of storing in std::string */
        std::string content;
        for (size_t i{0}; i < lines; ++i) {
            auto num = rand() % wrap;
            content += std::to_string(num) + '\n';
        }
        std::ofstream outfile(filepath);
        if (!outfile.is_open()) {
            std::cout << "unable to open '" << filepath << "'\n";
            return;
        }
        outfile.write(content.c_str(), content.size());
        outfile.close();
    }
};

#endif
