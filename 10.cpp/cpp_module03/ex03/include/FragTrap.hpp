#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap(void);
  FragTrap(const std::string _name);
  FragTrap(FragTrap const &instance);
  FragTrap &operator=(FragTrap const &rhs);
  ~FragTrap(void);
  void highFivesGuys(void);

 private:
};

#endif