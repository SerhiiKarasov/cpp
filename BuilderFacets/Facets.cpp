#include<iostream>
#include<string>
#include<vector>
#include<sstream>


using namespace std;


#include "Person.hpp"
#include "PersonBuilder.hpp"

int main()
{
    Person::create().lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
    .works().at("PragmaSoft").as_a("Consultant").earning(10e6);
}