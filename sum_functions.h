#ifndef SUM_FUNCTIONS_H
#define SUM_FUNCTIONS_H

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <thread>

class Sum {
public:
    static std::int64_t SequentialSum(
        const std::vector<int>& values
    );

    static std::int64_t MultiThreadedSum(
        const std::vector<int>& values,
        size_t thread_count
    );
    
    static std::vector<int> SourceToVec(
        const std::string& source
    );
};

#endif
