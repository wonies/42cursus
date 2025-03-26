#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance) {
  *this = instance;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this != &rhs) {
    _yy = rhs._yy;
    _mm = rhs._mm;
    _dd = rhs._dd;
    _val = rhs._val;
    // _maps = rhs._maps;
    _maps.insert(rhs._maps.begin(), rhs._maps.end());
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

bool BitcoinExchange::validInput(std::string input) {
  std::ifstream inputdata(input.c_str());
  std::string _line;

  if (!inputdata.is_open()) {
    std::cerr << "can't open" << std::endl;
    return false;
  }
  if (std::getline(inputdata, _line)) {
    if ((_line != "date | value")) return false;
  }
  while (std::getline(inputdata, _line)) {
    while (!_line.empty()) {
      char *endptr = NULL;
      if (!(inputvalid(_line))) break;
      _yy = std::strtod(_line.substr(0, 4).c_str(), &endptr);
      _mm = std::strtod(_line.substr(5, 2).c_str(), &endptr);
      _dd = std::abs(std::strtod(_line.substr(8, 2).c_str(), &endptr));
      _val = std::strtod(_line.substr(13, _line.find('\0')).c_str(), &endptr);
      if (*endptr != '\0') {
        std::cout << "Error: not only integer\n";
        break;
      }
      if (!(calandervalid())) break;
      mapdata(_line);
      _line.clear();
    }
    _line.clear();
  }
  return 0;
}

bool BitcoinExchange::database(void) {
  std::ifstream database("data.csv");
  char *endptr = NULL;
  if (!database.is_open()) {
    std::cerr << "database can't open" << std::endl;
    return false;
  }
  std::cout << std::setprecision(2);
  std::string line;

  if (std::getline(database, line)) {
    if ((line != "date,exchange_rate")) return false;
  }
  while (std::getline(database, line)) {
    std::string _sum =
        line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
    int atoisum = atoi(_sum.c_str());
    _maps[atoisum] =
        std::strtod(line.substr(11, line.find('\0')).c_str(), &endptr);
  }
  return true;
}

bool BitcoinExchange::inputvalid(std::string line) {
  if (line.find('|') != std::string::npos) {
    if (!(line[4] == '-') || !(line[7] == '-')) {
      std::cout << "Error: not valid input line\n";
      return false;
    } else if (!(line[10] == ' ' && line[12] == ' ')) {
      std::cout << "Error: not valid input line\n";
      return false;
    }
  } else {
    std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
    return false;
  }
  return true;
}

bool BitcoinExchange::calandervalid(void) {
  if (_yy % 4 != 0) {
    if (_mm == 2 && _dd > 28) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  } else {
    if (_mm == 2 && _dd > 29) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  }
  if (_mm < 1 || _mm > 12) {
    std::cout << "Error: bad input " << std::endl;
    return false;
  }
  if (_mm == 4 || _mm == 6 || _mm == 9 || _mm == 11) {
    if (_dd > 30) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  } else {
    if (_dd > 31) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  }
  if (_val > INT_MAX) {
    std::cout << "Error: too large a number" << std::endl;
    return false;
  } else if (_val < 0) {
    std::cout << "Error: not a positive number" << std::endl;
    return false;
  }
  return true;
}

bool BitcoinExchange::mapdata(std::string line) {
  char *endptr = NULL;
  std::string lineinput =
      line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
  int target = std::strtod(lineinput.c_str(), &endptr);
  std::map<int, double>::iterator it;
  for (it = _maps.begin(); it != _maps.end(); it++) {
    if (it->first == target) {
      std::cout << line.substr(0, 10) << " => " << _val << " = "
                << it->second * _val << std::endl;
      return true;
    }
  }
  std::map<int, double>::iterator lower = _maps.lower_bound(target);
  if (lower == _maps.begin()) {
    std::cout << "Error: can't find info" << std::endl;
    return false;
  }
  std::map<int, double>::iterator prevLower = lower;
  --prevLower;
  if (prevLower != _maps.end()) {
    std::cout << line.substr(0, 10) << " => " << _val << " = "
              << prevLower->second * _val << std::endl;
    return true;
  } else {
    std::cout << "database isn't exist\n";
    return false;
  }
  return true;
}
