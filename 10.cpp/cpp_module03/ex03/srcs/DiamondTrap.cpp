#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"),
      FragTrap(_name),
      ScavTrap(_name),
      Name(_name) {
  std::cout << "💎Diamond_Trap_CONSTRUCTOR💎" << std::endl;
  std::cout << "💎Name: 💎" << Name << std::endl;
  std::cout << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance)
    : ClapTrap(instance), FragTrap(instance), ScavTrap(instance) {
  *this = instance;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
    FragTrap::operator=(rhs);
    ScavTrap::operator=(rhs);
    this->Name = rhs.Name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "💎Diamond_TRAP__DESTRUCTOR💎" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "Base' Name \t" << getName() << std::endl;
  std::cout << "Diamond's Name \t" << Name << std::endl;
}
