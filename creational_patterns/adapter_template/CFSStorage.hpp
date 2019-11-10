#pragma once

#include "IPhyStorage.hpp"

class CFSStorage : public IPhyStorage
{
public:
  virtual void writeData(const std::string &buffer) override final;
  virtual std::string readData() override final;
  virtual ~CFSStorage(){};
  CFSStorage(){};
};