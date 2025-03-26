#include "MateriaSource.hpp"

#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(void) {
  for (int i = 0; i < slot; i++) _materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &instance) {
  *this = instance;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this != &rhs) {
  }
  return *this;
}

MateriaSource::~MateriaSource(void) {
  for (int i = 0; i < slot; i++) delete _materia[i];
}

void MateriaSource::learnMateria(AMateria *materia) {
  for (int i = 0; i < slot; i++)
    if (_materia[i] == NULL) _materia[i] = materia->clone();
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type == "ice")
    return new Ice();
  else if (type == "cure")
    return new Cure();
  else
    return NULL;
}
