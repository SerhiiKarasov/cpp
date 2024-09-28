
#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include "Integer.hpp"

class Product
{
private:
    int *m_pInt;

public:
    // destructor
    virtual ~Product();

    // default constuctor
    Product();
    // parametrized constructor
    Product(int value);
    // copy constructor
    Product(const Product &obj);
    // move constructor
    Product(Product &&obj);

    // preincrement operator
    Product &operator++();
    // postincrement operator
    Product operator++(int);
    // equality operator
    bool operator==(const Product &a) const;
    // copy assignment operator
    Product &operator=(const Product &a);
    // move assignment operator
    Product &operator=(Product &&a);
    // plus operator
    Product operator+(const Product &a) const;
    // function call operator.
    void operator()();

    int GetValue() const;
    void SetValue(int value);

    explicit operator int();
    operator Integer();
};

Product operator+(int x, const Product &y);
std::ostream &operator<<(std::ostream &out, const Product &a);
std::istream &operator>>(std::istream &in, const Product &a);

#endif // _PRODUCT_H
