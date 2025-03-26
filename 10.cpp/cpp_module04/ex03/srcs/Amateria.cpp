#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type)
    : _type(type) {
}  //  ㅊㅜ사ㅇ클래스를 바탕으로.. 자식이 어떤 생성자 불러올지 결정함

AMateria::AMateria(AMateria const &instance) { *this = instance; }

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

AMateria::~AMateria(void) {}

std::string const &AMateria::getType() const { return _type; }
