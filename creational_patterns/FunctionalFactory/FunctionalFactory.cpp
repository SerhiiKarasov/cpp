#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.hpp"
#include "DrinkFactory.hpp"
using namespace std;

//bad case, what if we need more types?
unique_ptr<HotDrink> make_drink(string type)
{
    unique_ptr<HotDrink> drink;
    if (type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else
    {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

int main()
{

    DrinkWithVolumeFactory dvf;
    dvf.make_drink("tea");
    return 0;
}