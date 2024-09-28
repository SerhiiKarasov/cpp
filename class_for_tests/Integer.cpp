#include "Integer.hpp"
#include <iostream>

// destructor
Integer::~Integer()
{
  std::cout << "~Integer()" << std::endl;
  delete m_pInt;
}

// default constuctor
Integer::Integer()
{
  std::cout << "Integer()" << std::endl;
  m_pInt = new int(0);
}

// parametrized constructor
Integer::Integer(int value)
{
  std::cout << "Integer(int value)" << std::endl;
  m_pInt = new int(value);
}

// copy constructor
Integer::Integer(const Integer &obj)
{
  std::cout << "Integer(const Integer &obj)" << std::endl;
  m_pInt = new int(*obj.m_pInt);
}

// move constructor
Integer::Integer(Integer &&obj)
{
  std::cout << "Integer(Integer &&obj)" << std::endl;
  m_pInt = obj.m_pInt;
  obj.m_pInt = nullptr;
}

// preincrement operator
Integer &Integer::operator++()
{
  std::cout << "Integer &Integer::operator++()" << std::endl;
  ++(m_pInt);
  return *this;
}

// postincrement operator
Integer Integer::operator++(int)
{
  std::cout << "Integer Integer::operator++(int)" << std::endl;
  Integer temp(*this);
  ++(*m_pInt);
  return temp;
}

// equality operator
bool Integer::operator==(const Integer &a) const
{
  std::cout << "bool Integer::operator==(const Integer &a) const" << std::endl;
  return *m_pInt == *a.m_pInt;
}

// copy assignment operator
Integer &Integer::operator=(const Integer &a)
{
  std::cout << "Integer &Integer::operator=(const Integer &a)" << std::endl;
  if (this != &a)
  {
    delete m_pInt;
    m_pInt = new int(*a.m_pInt);
  }
  return *this;
}
// move assignment operator
Integer &Integer::operator=(Integer &&a)
{
  std::cout << "Integer &Integer::operator=(Integer &&a)" << std::endl;
  if (this != &a)
  {
    delete m_pInt;
    m_pInt = a.m_pInt;
    a.m_pInt = nullptr;
  }

  return *this;
}
// plus operator
Integer Integer::operator+(const Integer &a) const
{
  std::cout << "Integer Integer::operator+(const Integer &a) const"
            << std::endl;
  Integer temp;
  *temp.m_pInt = *m_pInt + *a.m_pInt;
  return temp;
}

// function call operator.
void Integer::operator()()
{
  std::cout << "void Integer::operator()() -> " << *m_pInt << std::endl;
}

int Integer::GetValue() const
{
  std::cout << "int Integer::GetValue() const" << std::endl;

  if (m_pInt)
  {
    return *m_pInt;
  }
  return 0;
}

void Integer::SetValue(int value)
{
  std::cout << "void Integer::SetValue(int value) " << std::endl;
  *m_pInt = value;
}

Integer operator+(int x, const Integer &y)
{
  std::cout << "Integer operator +(int x, const Integer &y)" << std::endl;
  Integer temp;
  temp.SetValue(x + y.GetValue());
  return temp;
}

std::ostream &operator<<(std::ostream &out, const Integer &a)
{
  std::cout << "std::ostream &operator<<(std::ostream &out, const Integer &a)" << std::endl;

  out << a.GetValue();
  return out;
}

std::istream &operator>>(std::istream &input, Integer &a)
{
  std::cout << "std::istream &operator>>(std::istream &input, Integer &a)" << std::endl;
  int x;
  input >> x;
  a.SetValue(x);
  return input;
}

Integer::operator int()
{
  std::cout << "Integer::operator int()" << std::endl;
  return *m_pInt;
}
