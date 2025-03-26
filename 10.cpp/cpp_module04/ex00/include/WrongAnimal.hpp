#ifndef __WRONGANIMAL__H__
#define __WRONGANIMAL__H__

#include <iostream>

class WrongAnimal {
 protected:
  std::string type;

 public:
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal &instance);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  ~WrongAnimal(void);
  void makeSound(void) const;
};

#endif