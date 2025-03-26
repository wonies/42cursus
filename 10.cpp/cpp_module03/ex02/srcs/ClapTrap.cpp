#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) { std::cout << "🥚Base Constructor" << std::endl; }

ClapTrap::ClapTrap(std::string _name)
    : Name(_name), HitPoints(100), EnergyPoints(50), AttackDamage(20) {
  std::cout << "🥚Base Constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
    : Name(ct.Name),
      HitPoints(ct.HitPoints),
      EnergyPoints(ct.EnergyPoints),
      AttackDamage(ct.AttackDamage) {
  *this = ct;
}
// 성능이 중요한 상황에서는 복사연산자에서 바로 초기화하는 것이 낫다.

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
  if (this != &ct) {
    this->Name = ct.Name;
    this->HitPoints = ct.HitPoints;
    this->EnergyPoints = ct.EnergyPoints;
    this->AttackDamage = ct.AttackDamage;
  }
  return (*this);
}

ClapTrap::~ClapTrap(void) { std::cout << "Base Destructor🥚" << std::endl; }

void ClapTrap::attack(const std::string &target) {
  if (EnergyPoints <= 0 || HitPoints <= 0) return;
  std::cout << this->Name << " (은/는) " << target << " (을/를) "
            << AttackDamage << " 만큼 공격했다!⚡️" << std::endl;
  EnergyPoints--;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (EnergyPoints <= 0 || HitPoints <= 0) return;
  HitPoints -= amount;
  std::cout << this->Name << " (은/는) " << amount << " 만큼 공격받았다.💥"
            << std::endl;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (EnergyPoints <= 0 || HitPoints <= 0) {
    std::cout << Name << " (은/는) "
              << "죽었기 때문에 스스로를 치유할 수 없다🙌🏻" << std::endl;
    return;
  }
  EnergyPoints--;
  HitPoints += amount;
  std::cout << Name << " (은/는) " << amount << " 만큼 회복하였다.🍎 "
            << std::endl;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 10)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

std::string ClapTrap::getName(void) const { return Name; }
int ClapTrap::getHP(void) { return HitPoints; }
void ClapTrap::setHP(int hp) { HitPoints = hp; }
void ClapTrap::setAttackDamage(int ad) { AttackDamage = ad; }
void ClapTrap::setEnergyPoints(int ep) { EnergyPoints = ep; }