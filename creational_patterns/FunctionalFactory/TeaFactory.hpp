#pragma once
#include "HotDrinkFactory.hpp"

struct TeaFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() override
    {
        return std::make_unique<Tea>();
    }
};