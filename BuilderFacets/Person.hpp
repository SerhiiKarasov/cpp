#pragma once
#include <string>
using namespace std;

class PersonBuilder;

class Person
{
    //address
    string street_address, post_code, city;
    //employment
    string company_name, position;
    int annual_income = 0;
    Person() {}

public:
    static PersonBuilder create();
};

