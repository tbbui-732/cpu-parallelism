#include "sum_functions.h"

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <vector>
#include <sstream>

std::string Sum::ReadFile(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cout << "Unable to open " << file_path << "\n";
        return "";
    }
    std::string file_contents;
    std::string buffer;
    while (std::getline(file, buffer)) {
        file_contents += buffer;
        file_contents.push_back('\n');
    }
    file.close();
    return file_contents;
}

std::vector<int> Sum::SourceToVec(const std::string& source) {
    std::vector<int> result;
    std::ifstream stream(source);
    if (!stream) {
        std::cout << "failed to initialize input file stream\n";
        return result; // empty vector on failure
    }
    for (std::string buffer; std::getline(stream, buffer);) {
        int conv = std::stoi(buffer);
        result.push_back(conv);
    }
    stream.close();
    return result;
}

void Sum::SequentialSum() {
    return;
}

void Sum::MultiThreadedSum() {
    return;
}
