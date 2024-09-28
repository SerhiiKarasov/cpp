#ifndef _INTEGER_H
#define _INTEGER_H

#include <iostream>

class Integer {
private:
  int *m_pInt;

public:
  // destructor
  virtual ~Integer();

  // default constuctor
  Integer();
  // parametrized constructor
  Integer(int value);
  // copy constructor
  Integer(const Integer &obj);
  // move constructor
  Integer(Integer &&obj);

  // preincrement operator
  Integer &operator++();
  // postincrement operator
  Integer operator++(int);
  // equality operator
  bool operator==(const Integer &a) const;
  // copy assignment operator
  Integer &operator=(const Integer &a);
  // move assignment operator
  Integer &operator=(Integer &&a);
  // plus operator
  Integer operator+(const Integer &a) const;
  // function call operator.
  void operator()();

  int GetValue() const;
  void SetValue(int value);
};

Integer operator+(int x, const Integer &y);
std::ostream &operator<<(std::ostream &out, const Integer &a);
std::istream &operator>>(std::istream &in, const Integer &a);

#endif // _INTEGER_H
