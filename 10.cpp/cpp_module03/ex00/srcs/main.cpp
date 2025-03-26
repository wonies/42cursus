#include "ClapTrap.hpp"

int main(void) {
  ClapTrap pock("피카츄");

  pock.attack("잠만보");
  pock.attack("꼬부기");
  pock.attack("꼬부기");
  pock.attack("파이리");
  pock.beRepaired(1);
  pock.takeDamage(4);
  // ClapTrap::others(pock, 5);
  // ClapTrap::others_();
  return 0;
}
