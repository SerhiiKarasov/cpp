#include "TaskQueue.hpp"
#include "Storage.hpp"
#include <iostream>
#include <string>
constexpr auto FILE_LOCATION = "/tmp/datafile";

auto main() -> int
{
    std::cout << "Start" << std::endl;
    
    if(not(Storage::writeDataToFile(FILE_LOCATION, Storage::getListOfFiles("/tmp/fs"))))
    {
        std::cerr<<"Fail";
    }

}

