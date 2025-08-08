#ifndef SUM_FUNCTIONS_H
#define SUM_FUNCTIONS_H

#include <string>
#include <string_view>
#include <vector>

class Sum {
public:
    void SequentialSum();
    void MultiThreadedSum();
//TODO: UNCOMMENT THIS ONCE DONE TESTING! 
//private:
    std::string ReadFile(const std::string& source);
    std::vector<int> SourceToVec(const std::string& source);
};

#endif
