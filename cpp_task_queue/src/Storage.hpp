#pragma once

#include <string>
#include <vector>

class Storage
{
  public:
    static bool writeDataToFile(const std::string &file, const std::vector<std::string> &data);
    static std::vector<std::string> getListOfFiles(const std::string &root);
};