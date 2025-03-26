#include "Dog.hpp"

Dog::Dog(void) {
  type = "DOG";
  brain = new Brain();
  std::cout << "\033[0;35m*댕댕쓰 생성자*\033[0;30m" << std::endl;
}
Dog::Dog(const Dog &instance) : Animal(instance) { *this = instance; }
Dog &Dog::operator=(const Dog &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
Dog::~Dog(void) {
  std::cout << "\033[0;35m~댕댕쓰 소멸자~\033[0;30m" << std::endl;
  delete brain;
}
void Dog::makeSound(void) const { std::cout << "Bark!" << std::endl; }

void Dog::brainAllocate(void) const { brain[0] = Brain("wonie"); }

void Dog::brainSound(void) const { std::cout << "zzz" << std::endl; }

void Dog::brainAlert(void) const { brain[0] = "konie"; }