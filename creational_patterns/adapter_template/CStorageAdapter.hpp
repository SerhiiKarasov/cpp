
#pragma once

// derived classes
#include <memory>
#include "CLibStorage.hpp"
#include "IPhyStorage.hpp"
#include "CFSStorage.hpp"

template <class T>
class CStorageAdapter : public IPhyStorage
{
  public:
    CStorageAdapter();

    virtual void writeData(const std::string &buffer) override;
    virtual std::string readData() override;
    virtual ~CStorageAdapter(){};

  private:
    std::shared_ptr<T> mStorage;
    void writeDataSpecific(const T storage, std::string &buffer);
    std::string readDataSpecific(const T storage);
};

template <typename T>
CStorageAdapter<T>::CStorageAdapter() : mStorage(new T)
{
    std::string result = "CStorageAdapter readData default";
    std::cout << result << std::endl;
}

template <typename T>
std::string CStorageAdapter<T>::readData()
{
    std::string result = "CStorageAdapter readData";
    mStorage->readData();
    std::cout << result << std::endl;
    return result;
}

template <typename T>
void CStorageAdapter<T>::writeData(const std::string &buffer)
{
    mStorage->writeData(buffer);
    std::cout << "CStorageAdapter writeData " << buffer << std::endl;
}
