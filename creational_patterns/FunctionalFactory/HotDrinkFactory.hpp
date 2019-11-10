#pragma once
#include "HotDrink.hpp"

struct HotDrinkFactory
{
    virtual std::unique_ptr<HotDrink> make() = 0;
};