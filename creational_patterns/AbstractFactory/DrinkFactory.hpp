#pragma once
#include <string>
#include <map>
#include "HotDrinkFactory.hpp"
#include "CoffeeFactory.hpp"
#include "TeaFactory.hpp"
#include <functional>
using namespace std;

struct HotDrink;

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> factories;

public:
    DrinkFactory()
    {
        factories["coffee"] = make_unique<CoffeeFactory>();
        factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        auto drink = factories[name]->make();
        drink->prepare(200); // oops!
        return drink;
    }
};