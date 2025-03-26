#include "Convert.hpp"

Convert::Convert(void) {}

Convert::Convert(Convert const &instance) { *this = instance; }

Convert &Convert::operator=(Convert const &rhs) {
  if (this != &rhs) {
    strcpy(_end, rhs._end);
    _dinput = rhs._dinput;
    _int = rhs._int;
    _float = rhs._float;
    _char = rhs._char;
    _double = rhs._double;
    c = rhs.c;
    _input = rhs._input;
    errChar = rhs.errChar;
    errInt = rhs.errInt;
    errZero = rhs.errZero;
  }
  return *this;
}

Convert::~Convert(void) {}

Convert::Convert(double input) : _dinput(input) {}

int Convert::checkType(void) {
  if (checkInt())
    return type_int;
  else if (checkFloat())
    return type_float;
  else if (checkDouble())
    return type_double;
  else if (checkChar())
    return type_char;
  return type_literal;
}

void Convert::scalarType(std::string input) {
  _input = input;
  int type = checkType();
  if (pseudo())
    castPseudo();
  else if (type == type_int)
    castInt();
  else if (type == type_float)
    castFloat();
  else if (type == type_double)
    castDouble();
  else if (type == type_char)
    castChar();
  else
    caseLiteral();
}

bool Convert::pseudo(void) {
  errZero = 0;
  double temp = strtod(_input.c_str(), NULL);
  const double INF = std::numeric_limits<double>::infinity();
  if (temp > CHAR_MAX || temp < CHAR_MIN) errChar = -114;
  if (temp == 0) {
    errZero = -108;
  }
  if (std::isnan(temp) || temp == INF || temp == -INF)
    return 1;
  else
    return 0;
}

void Convert::castPseudo(void) {
  double temp = strtod(_input.c_str(), NULL);
  _float = static_cast<float>(temp);
  _double = temp;
  std::cout << std::showpoint << std::fixed << std::setprecision(1);
  std::cout << "char : impossible" << std::endl;
  std::cout << "int : impossible" << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

bool Convert::checkInt(void) {
  errChar = 0;
  errInt = 0;
  long temp = strtol(_input.c_str(), &_end, 10);
  if (temp > CHAR_MAX || temp < CHAR_MIN) errChar = -114;
  if (temp > INT_MAX || temp < INT_MIN) {
    errInt = -114;
    return 0;
  }
  if (_end != _input.c_str() && *_end == 0) {
    _int = static_cast<int>(temp);
    return 1;
  }
  return 0;
}

bool Convert::checkFloat(void) {
  float temp = strtof(_input.c_str(), &_end);

  if (_end != _input.c_str() && *_end == 'f' && *(_end + 1) == 0) {
    _float = static_cast<float>(temp);
    return 1;
  }
  return 0;
}

bool Convert::checkDouble(void) {
  double temp = strtod(_input.c_str(), &_end);

  if (_end != _input.c_str() && *_end == 0) {
    _double = static_cast<double>(temp);
    return 1;
  }
  return 0;
}

bool Convert::checkChar(void) {
  if (_input.size() == 1) {
    _char = static_cast<char>(_input[0]);
    return 1;
  } else if (_input.size() == 0) {
    _char = '\0';
    return 1;
  }
  return 0;
}

void Convert::castInt(void) {
  _char = static_cast<char>(_int);
  _float = static_cast<float>(_int);
  _double = static_cast<double>(_int);
  std::cout << std::showpoint << std::fixed << std::setprecision(1);
  if (errZero == -108)
    std::cout << "char : Non displayable" << std::endl;
  else if (errChar == -114)
    std::cout << "char : impossible" << std::endl;
  else
    std::cout << "char : " << _char << std::endl;
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castFloat(void) {
  _char = static_cast<char>(_float);
  _int = static_cast<int>(_float);
  _double = static_cast<float>(_float);
  std::cout << std::showpoint << std::fixed << std::setprecision(1);
  if (errInt == -114) {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
  } else {
    if (errZero == -108)
      std::cout << "char : Non displayable" << std::endl;
    else if (errChar == -114)
      std::cout << "char : impossible" << std::endl;
    else
      std::cout << "char : " << _char << std::endl;
    std::cout << "int : " << _int << std::endl;
  }
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castDouble(void) {
  _char = static_cast<char>(_double);
  _int = static_cast<int>(_double);
  _float = static_cast<float>(_double);
  std::cout << std::showpoint << std::fixed << std::setprecision(1);
  if (errInt == -114) {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
  } else {
    if (errZero == -108)
      std::cout << "char : Non displayable" << std::endl;
    else if (errChar == -114)
      std::cout << "char : impossible" << std::endl;
    else
      std::cout << "char : " << _char << std::endl;
    std::cout << "int : " << _int << std::endl;
  }
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castChar(void) {
  c = (_input[0]);
  std::cout << "char : " << _input[0] << std::endl;
  _int = static_cast<int>(c);
  _float = static_cast<float>(c);
  _double = static_cast<double>(c);
  std::cout << std::showpoint << std::fixed << std::setprecision(1);
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::caseLiteral(void) {
  std::cout << "char : "
            << "literal/ not displayable" << std::endl;
  std::cout << "int : "
            << "literal/ not displayable" << std::endl;
  std::cout << "float : "
            << "literal/ not displayable" << std::endl;
  std::cout << "double : "
            << "literal/ not displayable" << std::endl;
}
