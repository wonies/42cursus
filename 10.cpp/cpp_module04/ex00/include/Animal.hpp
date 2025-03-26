#ifndef __ANIMAL__H__
#define __ANIMAL__H__

#include <iostream>

class Animal {
 protected:
  std::string type;

 public:
  Animal(void);
  Animal(const Animal &instance);
  Animal &operator=(const Animal &rhs);
  virtual ~Animal(void);
  virtual void makeSound(void) const;
  std::string getType(void) const;
};

#endif