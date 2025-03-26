#include "Ice.hpp"

#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const &instance) : AMateria("ice") { *this = instance; }

Ice &Ice::operator=(const Ice &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

Ice::~Ice(void) {}

AMateria *Ice::clone() const {
  AMateria *ice = new Ice();
  return ice;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
