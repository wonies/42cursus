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
  int getHP(void);
  int getEnergy(void) const;
  int getDamage(void) const;
  void setHP(int hp);
  void setEnergyPoints(int ep);
  void setAttackDamage(int ad);
  std::string getName(void) const;
  void decreaseEnergy();

 protected:
 private:
  std::string Name;
  int HitPoints;
  int EnergyPoints;
  int AttackDamage;
};

#endif