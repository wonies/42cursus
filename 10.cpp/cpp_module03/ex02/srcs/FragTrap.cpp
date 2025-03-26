#include <FragTrap.hpp>

FragTrap::FragTrap(void) { std::cout << "🍳Derived " << std::endl; }

FragTrap::FragTrap(std::string _name) : ClapTrap(_name) {
  std::cout << "🍳Derived "
               "Constructor\n\n-----------------FIGHTING!!-------------------\n"
            << std::endl;
  setHP(100);
  setEnergyPoints(100);
  setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &instance) : ClapTrap(instance) {
  *this = instance;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

FragTrap::~FragTrap(void) { std::cout << "More Cheer up!" << std::endl; }

void FragTrap::highFivesGuys(void) {
  bool select;
  std::cout << getName() << " (은/는) 함께 화이팅 하고 싶어한다." << std::endl;
  std::cout << "화이팅 하고 싶다면 1번을, 그것이 아니라면 0번을 선택하세요.\n";
  std::cin >> select;
  if (select == 1)
    std::cout << "하이파이브 !!!!!!! 🏏" << std::endl;
  else
    std::cout << "시무룩 🐿" << std::endl;
}