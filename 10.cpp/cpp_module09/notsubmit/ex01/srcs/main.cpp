#include "RPN.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: argument not valid\n";
    return 0;
  }
  RPN cal;
  std::string input(av[1]);
  cal.enter(input);

  return 0;
}