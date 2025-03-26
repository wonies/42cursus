#include "Cat.hpp"

Cat::Cat(void) {
  type = "CAT";
  brain = new Brain();
  std::cout << "\033[0;34m*냥냥이 생성자*\033[0;30m" << std::endl;
}

Cat::Cat(const Cat &instance) : AAnimal(instance) {
  std::cout << "copy in\n";
  *this = instance;
}

Cat &Cat::operator=(const Cat &rhs) {
  if (this != &rhs) {
    std::cout << "operator\n";
    type = rhs.type;
    delete this->brain;  // 새로 기본생성자에서 할당된 Brain delete!!
    //   std::cout << "after delete\n";
    if (rhs.brain) {
      std::cout << "22 after delete\n";
      brain = new Brain(*rhs.brain);
    } else
      brain = NULL;
    // }
  }
  return *this;
}

Cat::~Cat(void) {
  std::cout << "\033[0;34m~냥냥이 소멸자~\033[0;30m" << std::endl;
  delete brain;
}

void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }

void Cat::brainAllocate(void) const { brain[0] = "wonie"; }

void Cat::brainAlert(void) const { brain[0] = "konie"; }

void Cat::brainSound(void) const {
  std::cout << brain[0] << std::endl;
  std::cout << &brain[0] << std::endl;
}
