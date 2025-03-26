#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap ddt("치코리타");

  ddt.attack("이상해씨");
  ddt.takeDamage(59);
  ddt.beRepaired(6);
  ddt.highFivesGuys();
  ddt.guardGate();
  ddt.whoAmI();

  return 0;
}
