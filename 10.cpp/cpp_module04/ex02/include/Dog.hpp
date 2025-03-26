#ifndef __DOG__H__
#define __DOG__H__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 public:
  Dog(void);
  Dog(const Dog &instance);
  Dog &operator=(const Dog &rhs);
  ~Dog(void);
  void makeSound(void) const;
  void brainAllocate(void) const;
  void brainSound(void) const;
  void brainAlert(void) const;

 private:
  Brain *brain;
};

#endif