#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter {
 public:
  Character(void);
  Character(const std::string &name);
  Character(Character const &instance);
  Character &operator=(Character const &rhs);
  ~Character(void);
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  void deleteInven(int idx);

 private:
  AMateria *inventory[slot];
};

#endif