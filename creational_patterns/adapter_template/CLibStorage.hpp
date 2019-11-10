
#include "IPhyStorage.hpp"

class CLibStorage : public IPhyStorage
{
  public:
    virtual void writeData(const std::string &buffer) override;
    virtual std::string readData() override;
    virtual ~CLibStorage(){};
    CLibStorage(){};

};