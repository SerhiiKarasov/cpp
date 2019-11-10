#pragma once
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() override
    {
        return std::make_unique<Coffee>();
    }
};