#pragma once

#include <iostream>

class IPhyStorage
{
public:
  virtual void writeData(const std::string &buffer) = 0;
  virtual std::string readData() = 0;
  virtual ~IPhyStorage(){};
};
