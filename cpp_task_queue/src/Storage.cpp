#include "Storage.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

std::vector<std::string> Storage::getListOfFiles(const std::string& root)
{
    std::vector<std::string> result{};
    for (const auto& filePath : fs::recursive_directory_iterator(root)) {
        std::cout << filePath << '\n';
        result.push_back(filePath.path().string());
    }
    return result;
}

bool Storage::writeDataToFile(const std::string& file, const std::vector<std::string>& data)
{
    std::ofstream dataFile;
    dataFile.open(file.c_str(), std::ofstream::out);
    if (dataFile.is_open()) {
        std::cout << "Starting to write data to " << file.c_str() << std::endl;
        for (const auto& dataPart : data) {
            dataFile << dataPart.c_str() << "\n";
        }
    } else {
        std::cerr << "Failed to write data to " << file.c_str() << " " << data.size() << " files" << std::endl;
        return false;
    }
    std::cout << "Finished to write data to " << file.c_str() << " " << data.size() << " files" << std::endl;

    return true;
}