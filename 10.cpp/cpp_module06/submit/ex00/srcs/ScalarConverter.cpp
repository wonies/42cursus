#include "ScalarConverter.hpp"

#include "Convert.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &instance) {
  *this = instance;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  if (this != &rhs) {
  }
  return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string input) {
  Convert scalar;
  scalar.scalarType(input);
}
