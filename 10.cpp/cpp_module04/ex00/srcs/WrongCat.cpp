#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
  std::cout << "\033[0;34m*wrong_냥냥이 생성자*\033[0;30m" << std::endl;
}
WrongCat::WrongCat(const WrongCat &instance) : WrongAnimal(instance) {
  *this = instance;
}
WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
WrongCat::~WrongCat(void) {
  std::cout << "\033[0;34m~wrong_냥냥이 소멸자~\033[0;30m" << std::endl;
}

void WrongCat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
