#include "Dog.hpp"

Dog::Dog(void) {
  type = "DOG";
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
}

void Dog::makeSound(void) const { std::cout << "Bark!" << std::endl; }
