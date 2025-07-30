#include "sum_functions.h"

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>

std::string Sum::_ReadFile() const {
    ifstream file(Sum::file_path);
    if (!file.is_open()) {
        std::cout << "Unable to open " << Sum::file_path << "\n";
        return "";
    }
    std::string file_contents;
    std::string buffer;
    while (std::getline(file, buffer)) {
        file_contents += buffer;
        file_contents.push_back('\n');
    }
    return file_contents;
}

Sum::MultiThreadedSum() const {

}

