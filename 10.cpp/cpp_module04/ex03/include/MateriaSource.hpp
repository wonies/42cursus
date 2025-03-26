#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class Ice;
class Cure;

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &instance);
  MateriaSource &operator=(MateriaSource const &rhs);
  ~MateriaSource(void);
  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);

 private:
  AMateria *_materia[5];
};

#endif