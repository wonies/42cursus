#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <climits>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <limits>
#include <string>

#include "ScalarConverter.hpp"

enum type_define {
  type_int = 0,
  type_float,
  type_double,
  type_char,
  type_literal,
};

class Convert {
 public:
  Convert(void);
  Convert(double input);
  Convert(std::string inputs);
  Convert(Convert const &instance);
  Convert &operator=(Convert const &rhs);
  ~Convert(void);
  void scalarType(std::string input);
  int checkType();
  void castInt(void);
  void castFloat(void);
  void castDouble(void);
  void castChar(void);
  void caseLiteral(void);
  bool charInput(void);
  bool checkInt(void);
  bool checkFloat(void);
  bool checkChar(void);
  bool checkDouble(void);
  bool pseudo(void);
  void castPseudo(void);

 private:
  char *_end;
  double _dinput;
  int _int;
  float _float;
  char _char;
  double _double;
  unsigned int c;
  std::string _input;
  int errChar;
  int errInt;
  int errZero;
};

#endif