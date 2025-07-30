#ifndef SUM_FUNCTIONS_H
#define SUM_FUNCTIONS_H

#include <string>
#include <string_view>

struct Sum {

    /*
     * Read-only string of the file containing the array to be summed
     */
    std::string_view file_path;

    /*
     * Stores content of @file_path in a std::string object
     * Returns string content if SUCCESSFUL; otherwise an empty string ""
     */
    std::string _ReadFile() const;


    void SequentialSum() const;
    void MultiThreadedSum() const;
};

#endif
