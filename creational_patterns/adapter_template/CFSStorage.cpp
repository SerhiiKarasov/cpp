#include "CFSStorage.hpp"

std::string CFSStorage::readData()
{
    std::string result = "CFSStorage readData";
    std::cout << result << std::endl;
    return result;
}

void CFSStorage::writeData(const std::string &buffer)
{
    std::cout << "CFSStorage writeData " << buffer << std::endl;
}