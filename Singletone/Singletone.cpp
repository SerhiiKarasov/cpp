// When piecewise object construction is complicated, Builder provides and API for doing that succintly.
// The Builder Pattern decouples the creation of the object from the object itself. 
// The main idea behind is that an object does not have to be responsible for its own creation.
// The correct and valid assembly of a complex object may be a complicated task in itself, so this task can be delegated to another class.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
using namespace std;
#include "Singletone.hpp"

int main(int ac, char* av[])
{
    SingletoneDatabase::get();
}