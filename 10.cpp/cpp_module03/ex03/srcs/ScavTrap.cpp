#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) { std::cout << "🍳Derived Constructor" << std::endl; }

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name) {
  std::cout << "🍳Derived "
               "Constructor\n\n------------------START OF THE "
               "GAME-------------------\n"
            << std::endl;
  setEnergyPoints(50);
}

ScavTrap::ScavTrap(const ScavTrap &instance) : ClapTrap(instance) {
  *this = instance;
};

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

void ScavTrap::attack(const std::string &target) {
  if (getEnergy() <= 0 || getHP() <= 0) return;
  std::cout << "ScavTrap" << getName() << " (은/는) " << target << " (을/를)"
            << getDamage() << " 만큼 공격했다!🌪🌪🌪(  [override]  )"
            << std::endl;
  decreaseEnergy();
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << getEnergy() << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << getHP() << std::endl;
  if (getEnergy() <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ScavTrap::guardGate() {
  int yours;
  std::cout
      << "\n아군을 고르세요. *숫자로 오로지 작성해주세요!*\n1. 파이리\n2. "
         "꼬부기\n3. 치코리타"
      << std::endl;
  std::cin >> yours;
  std::string yourmon;
  if (yours == 1)
    yourmon = "파이리";
  else if (yours == 2)
    yourmon = "꼬부기";
  else if (yours == 3)
    yourmon = "치코리타";
  else
    std::cout << "도와줄 수 있는 아군이 아님." << std::endl;
  if (getHP() <= 0) {
    std::cout << std::endl;
    std::cout
        << yourmon
        << " (은/는) 주인공을 보호할 수 없다.\n사유: 보호받는 포켓몬의 탈진"
        << std::endl;
  } else
    std::cout << yourmon << " (은/는) 주인공을 보호한다." << std::endl;
}