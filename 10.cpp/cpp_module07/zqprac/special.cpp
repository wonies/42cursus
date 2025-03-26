#include <iostream>

template <typename T>
T Max(T a, T b) {
  return a > b ? a : b;
}

int main(void) {
  std::cout << Max(11, 15) << std::endl;
  std::cout << Max('T', 'Q') << std::endl;
  std::cout << Max("wonie", "konie") << std::endl;
}