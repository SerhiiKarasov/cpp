#include "CLibStorage.hpp"

std::string CLibStorage::readData()
{
    std::string result = "CLibStorage readData";
    std::cout << result << std::endl;
    return result;
}

void CLibStorage::writeData(const std::string &buffer)
{
    std::cout << "CLibStorage writeData " << buffer << std::endl;
}
