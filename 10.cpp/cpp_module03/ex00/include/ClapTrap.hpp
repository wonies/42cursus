#ifndef __CLAPTRAP__H__
#define __CLAPTRAP__H__

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(void);
  ClapTrap(const ClapTrap &ct);
  ClapTrap &operator=(const ClapTrap &ct);
  ~ClapTrap(void);
  ClapTrap(std::string _name);
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  // static void others(ClapTrap &ct, unsigned int _amount);
  // static void others_();

 protected:
 private:
  std::string Name;
  int HitPoints;
  int EnergyPoints;
  int AttackDamage;
  // static int Mem; //정적변수 초기화할 때.
};

#endif