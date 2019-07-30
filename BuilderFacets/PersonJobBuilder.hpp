#pragma once
#include <string>
#include "PersonBuilder.hpp"
using namespace std;

class PersonJobBuilder : public PersonBuilder
{
    typedef PersonJobBuilder Self;

public:
    explicit PersonJobBuilder(Person &person)
        : PersonBuilder(person)
    {
    }

    Self &at(string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    Self &as_a(string position)
    {
        person.position = position;
        return *this;
    }
    Self &earning(int earning)
    {
        person.annual_income = earning;
        return *this;
    }
};