#include "Fridge.hpp"

int main()
{
    // since Fridge.hpp includes Engine.hpp, any client of Fridge class will inderectly include Engine class.
    // Hence all Fridge clients would be recompiled if Engine changes.
    Fridge fridge;
    fridge.coolDown();
}
