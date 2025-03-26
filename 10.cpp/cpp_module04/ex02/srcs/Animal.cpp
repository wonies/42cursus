#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
  std::cout << "\033[0;31m*AAnimal 생성자*\033[0;30m" << std::endl;
}
AAnimal::AAnimal(const AAnimal &instance) : type(instance.type) {
  *this = instance;
}
AAnimal &AAnimal::operator=(const AAnimal &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}
AAnimal::~AAnimal(void) {
  std::cout << "\033[0;31m~AAnimal 소멸자~\033[0;30m" << std::endl;
}

std::string AAnimal::getType(void) const { return type; }