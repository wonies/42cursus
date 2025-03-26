#include "Cat.hpp"

Cat::Cat(void) {
  type = "CAT";
  std::cout << "\033[0;34m*냥냥이 생성자*\033[0;30m" << std::endl;
}
Cat::Cat(const Cat &instance) : Animal(instance) { *this = instance; }
Cat &Cat::operator=(const Cat &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
Cat::~Cat(void) {
  std::cout << "\033[0;34m~냥냥이 소멸자~\033[0;30m" << std::endl;
}

void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
