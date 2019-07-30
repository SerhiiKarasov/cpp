#pragma once
#include <string>
#include "PersonBuilder.hpp"
using namespace std;

class PersonAddressBuilder : public PersonBuilder
{
    typedef PersonAddressBuilder Self;

public:
    explicit PersonAddressBuilder(Person &person)
        : PersonBuilder(person)
    {
    }

    Self &at(string street_address)
    {
        person.street_address = street_address;
        return *this;
    }

    Self &with_poscode(string post_code)
    {
        person.post_code = post_code;
        return *this;
    }
    Self &in(string city)
    {
        person.city = city;
        return *this;
    }

};