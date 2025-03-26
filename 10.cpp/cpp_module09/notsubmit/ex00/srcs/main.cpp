#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  BitcoinExchange btcoin;

  if (ac != 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 0;
  }
  btcoin.database();
  std::string input(av[1]);
  btcoin.validInput(input);

  // BitcoinExchange coin(btcoin);
  // std::map<int, double>::iterator it;
  // for (it = coin._maps.begin(); it != coin._maps.end(); it++) {
  //   std::cout << it->first << std::endl;
  // }
  return 0;
}
