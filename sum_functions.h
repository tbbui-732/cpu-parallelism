#ifndef SUM_FUNCTIONS_H
#define SUM_FUNCTIONS_H

#include <string>
#include <string_view>

struct Sum {
    std::string_view file_path;
    void SequentialSum() const;
    void MultiThreadedSum() const;
};

#endif
