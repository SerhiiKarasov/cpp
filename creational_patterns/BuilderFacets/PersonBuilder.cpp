#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

PersonAddressBuilder PersonBuilder::lives()
{
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilder::works()
{
    return PersonJobBuilder{person};
}