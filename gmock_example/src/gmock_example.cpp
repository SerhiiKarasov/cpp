#include <iostream>
#include "FCFileInfo.hpp"

int main()
{
    FCFileInfoInterface * file = new FCFileInfo{"/tmp/file1"};
    std::cout << file->getFilePath() << std::endl;
}