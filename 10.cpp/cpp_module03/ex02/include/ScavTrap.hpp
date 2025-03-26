#ifndef __SCAVTRAP__H__
#define __SCAVTRAP__H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(void);
  ScavTrap(const std::string _name);
  ScavTrap(ScavTrap const &instance);
  ScavTrap &operator=(ScavTrap const &rhs);
  ~ScavTrap(void);
  void guardGate(void);

 private:
};

#endif