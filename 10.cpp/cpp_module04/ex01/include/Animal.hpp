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
  virtual void brainAllocate() const = 0;  // 순수 가상 함수로 선언
  virtual void brainSound() const = 0;
  virtual void brainAlert(void) const = 0;
};

#endif