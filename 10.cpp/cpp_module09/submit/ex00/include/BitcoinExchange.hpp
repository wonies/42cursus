#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const &instance);
  BitcoinExchange &operator=(BitcoinExchange const &rhs);
  ~BitcoinExchange(void);
  bool validInput(std::string input);
  bool calandervalid(void);
  bool inputvalid(std::string line);
  bool mapdata(std::string line);
  bool database(void);
  std::map<int, double> _maps;

 private:
  int _yy;
  int _mm;
  int _dd;
  double _val;
};

#endif
