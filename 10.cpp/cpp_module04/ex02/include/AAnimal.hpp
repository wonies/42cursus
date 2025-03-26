#ifndef __ANIMAL__H__
#define __ANIMAL__H__

#include <iostream>

class AAnimal {
 protected:
  std::string type;

 public:
  AAnimal(void);
  AAnimal(const AAnimal &instance);
  AAnimal &operator=(const AAnimal &rhs);
  virtual ~AAnimal(void);
  virtual void makeSound(void) const = 0;
  virtual void brainAllocate() const = 0;
  virtual void brainSound() const = 0;
  virtual void brainAlert(void) const = 0;
  std::string getType(void) const;
};

#endif