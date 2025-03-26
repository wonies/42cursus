#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) { std::cout << "🍳Derived Constructor" << std::endl; }

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name) {
  std::cout << "🍳Derived "
               "Constructor\n\n------------------START OF THE "
               "GAME-------------------\n"
            << std::endl;
  setHP(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &instance) : ClapTrap(instance) { *this = instance; };

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "\n---------------------THE END--------------------\nDerived "
               "Destructor🍳"
            << std::endl;
}

void ScavTrap::guardGate() {
  std::string yours;
  std::cout
      << "\n아군을 고르세요. *오로지 문자로만 작성하세요!*\n1. 파이리\n2. "
         "꼬부기\n3. 치코리타"
      << std::endl;
  std::cin >> yours;
  if (getHP() <= 0) {
    std::cout << std::endl;
    std::cout
        << yours
        << " (은/는) 주인공을 보호할 수 없다.\n사유: 보호받는 포켓몬의 탈진"
        << std::endl;
  } else
    std::cout << yours << " (은/는) 주인공을 보호한다." << std::endl;
}