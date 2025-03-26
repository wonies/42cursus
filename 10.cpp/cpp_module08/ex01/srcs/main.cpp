#include "Span.hpp"

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  // sp.addNumber(14);

  try {
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}