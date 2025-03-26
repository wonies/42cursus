#include "Cure.hpp"

#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const &instance) : AMateria("cure") { *this = instance; }

Cure &Cure::operator=(Cure const &rhs) {
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

Cure::~Cure(void) {}

AMateria *Cure::clone() const {
  AMateria *cure = new Cure();
  return cure;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
