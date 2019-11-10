#include "CStorageManager.hpp"

CStorageManager::CStorageManager() : mStorage(new CStorageAdapter<CLibStorage>)

{
    std::cout << "CStorageManager" << std::endl;
    mStorage->readData();
}
