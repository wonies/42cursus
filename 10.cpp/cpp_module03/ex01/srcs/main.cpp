#include "ScavTrap.hpp"

int main(void) {
  ScavTrap shiriff("피카");

  shiriff.attack("🦊이브이");
  shiriff.attack("🐡야도란");
  shiriff.attack("💨또도가스");
  shiriff.takeDamage(99);
  shiriff.takeDamage(10);
  shiriff.beRepaired(30);
  shiriff.guardGate();
  return 0;
}
