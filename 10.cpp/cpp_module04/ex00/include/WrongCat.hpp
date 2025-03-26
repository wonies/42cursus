#ifndef __WRONGCAT__H__
#define __WRONGCAT__H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat(void);
  WrongCat(const WrongCat &instance);
  WrongCat &operator=(const WrongCat &rhs);
  ~WrongCat(void);
  void makeSound(void) const;
};

#endif