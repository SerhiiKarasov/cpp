#pragma once

#include "CStorageAdapter.hpp"
#include "IPhyStorage.hpp"

class CStorageManager
{
  std::shared_ptr<IPhyStorage> mStorage;

public:
  CStorageManager();
};
