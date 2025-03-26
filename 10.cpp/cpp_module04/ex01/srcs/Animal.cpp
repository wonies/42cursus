#include "Animal.hpp"

Animal::Animal(void) {
  std::cout << "\033[0;31m*Animal 생성자*\033[0;30m" << std::endl;
}
Animal::Animal(const Animal &instance) : type(instance.type) {
  *this = instance;
}
Animal &Animal::operator=(const Animal &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}
Animal::~Animal(void) {
  std::cout << "\033[0;31m~Animal 소멸자~\033[0;30m" << std::endl;
}

void Animal::makeSound(void) const { std::cout << "some Sound" << std::endl; }

std::string Animal::getType(void) const { return type; }