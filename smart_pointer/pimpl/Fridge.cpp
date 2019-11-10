#include "Engine.hpp"
#include "Fridge.hpp"
#include <iostream>

class Fridge::FridgeImpl 
{
public:
    void coolDown()
    {
        std::cout << "FridgeImpl coolDown" << std::endl;
    }

private:
    Engine engine_;
};

Fridge::Fridge() : impl_(new FridgeImpl) {}

Fridge::~Fridge() = default;

void Fridge::coolDown()
{
   impl_->coolDown();
}