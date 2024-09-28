#include "Product.hpp"
#include <iostream>

// destructor
Product::~Product()
{
    std::cout << "~Product()" << std::endl;
    delete m_pInt;
}

// default constuctor
Product::Product()
{
    std::cout << "Product()" << std::endl;
    m_pInt = new int(0);
}

// parametrized constructor
Product::Product(int value)
{
    std::cout << "Product(int value)" << std::endl;
    m_pInt = new int(value);
}

// copy constructor
Product::Product(const Product &obj)
{
    std::cout << "Product(const Product &obj)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

// move constructor
Product::Product(Product &&obj)
{
    std::cout << "Product(Product &&obj)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

// preincrement operator
Product &Product::operator++()
{
    std::cout << "Product &Product::operator++()" << std::endl;
    ++(m_pInt);
    return *this;
}

// postincrement operator
Product Product::operator++(int)
{
    std::cout << "Product Product::operator++(int)" << std::endl;
    Product temp(*this);
    ++(*m_pInt);
    return temp;
}

// equality operator
bool Product::operator==(const Product &a) const
{
    std::cout << "bool Product::operator==(const Product &a) const" << std::endl;
    return *m_pInt == *a.m_pInt;
}

// copy assignment operator
Product &Product::operator=(const Product &a)
{
    std::cout << "Product &Product::operator=(const Product &a)" << std::endl;
    if (this != &a)
    {
        delete m_pInt;
        m_pInt = new int(*a.m_pInt);
    }
    return *this;
}
// move assignment operator
Product &Product::operator=(Product &&a)
{
    std::cout << "Product &Product::operator=(Product &&a)" << std::endl;
    if (this != &a)
    {
        delete m_pInt;
        m_pInt = a.m_pInt;
        a.m_pInt = nullptr;
    }

    return *this;
}
// plus operator
Product Product::operator+(const Product &a) const
{
    std::cout << "Product Product::operator+(const Product &a) const"
              << std::endl;
    Product temp;
    *temp.m_pInt = *m_pInt + *a.m_pInt;
    return temp;
}

// function call operator.
void Product::operator()()
{
    std::cout << "void Product::operator()() -> " << *m_pInt << std::endl;
}

int Product::GetValue() const
{
    std::cout << "int Product::GetValue() const" << std::endl;

    if (m_pInt)
    {
        return *m_pInt;
    }
    return 0;
}

void Product::SetValue(int value)
{
    std::cout << "void Product::SetValue(int value) " << std::endl;
    *m_pInt = value;
}

Product operator+(int x, const Product &y)
{
    std::cout << "Product operator +(int x, const Product &y)" << std::endl;
    Product temp;
    temp.SetValue(x + y.GetValue());
    return temp;
}

std::ostream &operator<<(std::ostream &out, const Product &a)
{
    std::cout << "std::ostream &operator<<(std::ostream &out, const Product &a)" << std::endl;

    out << a.GetValue();
    return out;
}

std::istream &operator>>(std::istream &input, Product &a)
{
    std::cout << "std::istream &operator>>(std::istream &input, Product &a)" << std::endl;
    int x;
    input >> x;
    a.SetValue(x);
    return input;
}

Product::operator int()
{
    std::cout << "Product::operator int()" << std::endl;
    return *m_pInt;
}

Product::operator Integer()
{
    std::cout << "Product::operator Integer()" << std::endl;

    Integer temp{*m_pInt};
    return temp;
}