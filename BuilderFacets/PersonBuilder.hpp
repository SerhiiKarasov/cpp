#pragma once
#include "Person.hpp"
#include <string>
using namespace std;

class PersonBuilder
{
    Person p;

protected:
    Person &person;
    explicit PersonBuilder(Person &person)
        : person{person}
    {
    }

public:
    PersonBuilder() : person { p } {}
};
