#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  BitcoinExchange btcoin;
  std::string inputfile;

  inputfile = av[1];
  if (ac != 2) {
    std::cout << "argument must be 2" << std::endl;
    return 0;
  }
  std::ifstream database("data.csv");    // 파일 열기
  std::ifstream inputdata("input.txt");  // 파일 열기

  if (!database.is_open()) {
    std::cerr << "파일을 열 수 없습니다." << std::endl;
    return 1;
  }
  std::cout << std::fixed << std::setprecision(2);
  std::string line;
  char *_end;
  std::map<std::string, double> _maps;
  while (std::getline(database, line)) {
    btcoin._yy = atoi(line.substr(0, 4).c_str());
    btcoin._mm = atoi(line.substr(5, 6).c_str());
    btcoin._dd = atoi(line.substr(8, 9).c_str());
    btcoin._val = strtod(line.substr(11, line.find('\0')).c_str(), &_end);
    _maps[line.substr(0, 10)] =
        strtod(line.substr(11, line.find('\0')).c_str(), &_end);

    std::cout << "year : " << btcoin._yy << std::endl;
    std::cout << "month : " << btcoin._mm << std::endl;
    std::cout << "day : " << btcoin._dd << std::endl;
    std::cout << "val : " << btcoin._val << std::endl;
  }

  while (std::getline(inputdata, line)) {
    while (inputdata) }
  std::map<std::string, double>::iterator it;

  for (it = _maps.begin(); it != _maps.end(); it++) {
    std::cout << it->first << ":" << it->second << std::endl;
  }

  database.close();  // 파일 닫기
  return 0;
}