#ifndef __DOG__H__
#define __DOG__H__

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog(void);
  Dog(const Dog &instance);
  Dog &operator=(const Dog &rhs);
  ~Dog(void);
  void makeSound(void) const;
};

#endif