#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
 public:
  virtual ~Base(void);
  void identify(Base* p);
  void identify(Base& p);

 private:
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
#endif