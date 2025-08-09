#ifndef SUM_FUNCTIONS_H
#define SUM_FUNCTIONS_H

#include <string>
#include <string_view>
#include <vector>

class Sum {
public:
    static int SequentialSum(const std::vector<int> values);
    static int MultiThreadedSum(const std::vector<int> values);
    static std::vector<int> SourceToVec(const std::string& source);
};

#endif
