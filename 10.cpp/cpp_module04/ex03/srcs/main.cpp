#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// void leak() { system("leaks a.out"); }

int main(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  me->unequip(0);

  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->unequip(1);
  // dynamic_cast<Character*>(me)->deleteInven(1);
  me->use(1, *bob);
  tmp = src->createMateria("ice");

  me->equip(tmp);
  me->use(0, *bob);

  delete bob;
  delete me;
  delete src;
  // leak();
  return 0;
}