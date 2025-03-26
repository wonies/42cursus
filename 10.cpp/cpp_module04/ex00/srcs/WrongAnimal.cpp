#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
  std::cout << "\033[0;31m*WrongAnimal 생성자*\033[0;30m" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &instance) : type(instance.type) {
  *this = instance;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}
WrongAnimal::~WrongAnimal(void) {
  std::cout << "\033[0;31m~WrongAnimal 소멸자~\033[0;30m" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "some Sound" << std::endl;
}
