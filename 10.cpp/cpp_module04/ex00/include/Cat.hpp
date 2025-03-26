#ifndef __CAT__H__
#define __CAT__H__

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat(void);
  Cat(const Cat &instance);
  Cat &operator=(const Cat &rhs);
  ~Cat(void);
  void makeSound(void) const;
};

#endif