#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  DiamondTrap(void);
  DiamondTrap(std::string diamond);
  DiamondTrap(DiamondTrap const &instance);
  DiamondTrap &operator=(DiamondTrap const &rhs);
  ~DiamondTrap(void);
  void whoAmI(void);

 private:
  std::string Name;
};

#endif