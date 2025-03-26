#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"
#define slot 4

class ICharacter;

class AMateria {
 public:
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(AMateria const &instance);
  AMateria &operator=(AMateria const &rhs);
  virtual ~AMateria(void);
  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target) = 0;

 protected:
  std::string _type;

 private:
};

#endif