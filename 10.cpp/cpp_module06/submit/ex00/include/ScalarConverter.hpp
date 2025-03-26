#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <stdlib.h>

#include <iostream>

class Convert;

class ScalarConverter {
 public:
  static void convert(std::string input);

 private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &instance);
  ScalarConverter &operator=(ScalarConverter const &rhs);
  ~ScalarConverter(void);
};

#endif