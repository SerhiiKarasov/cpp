#pragma once
#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder
{
    Person p;

protected:
    Person &person;
    explicit PersonBuilder(Person &person_build)
        : person{person_build}
    {
    }

public:
    PersonBuilder() : person{p}
    {
    }

    operator Person()
    {
        return std::move(person);
    }

    // builder facets

    PersonAddressBuilder lives();
    PersonJobBuilder works();
};
