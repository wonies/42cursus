#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
 public:
  Ice(void);
  Ice(Ice const &instance);
  Ice &operator=(Ice const &rhs);
  ~Ice(void);
  AMateria *clone() const;
  void use(ICharacter &target);

 private:
};

#endif
