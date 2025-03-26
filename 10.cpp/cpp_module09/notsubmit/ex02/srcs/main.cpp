#include "Pmerge.hpp"

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "invalid\n";
    return 0;
  }
  Pmerge pm;
  int i = 0;
  while (av[++i]) {
    pm._vector.push_back(std::stoi(av[i]));
    pm._deque.push_back(std::stoi(av[i]));
  }
  for (int i = 0; i < 6; i++) std::cout << pm._vector[i] << " ";
  std::cout << "\n";
  pm._size = pm._vector.size();
  // pm.pairsplit(0, pm._size - 1);
  // pm.pairsplit();
  pm.pair(0, 5, 0);
  for (int i = 0; i < 6; i++) std::cout << pm._vector[i] << " ";
  pm.mainchain();
  // pm.pendtomain();
  std::cout << "\n";
  for (int i = 0; i < 3; i++) std::cout << pm._mainchain[i] << " ";
  std::cout << "\n";

  for (int i = 0; i < 3; i++) std::cout << pm._pending[i] << " ";
  for (int i = 0; i < 6; i++) std::cout << pm._mainchain[i] << " ";

  return 0;
}