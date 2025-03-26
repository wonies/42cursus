#include "Base.hpp"

int main(void) {
  std::srand(static_cast<unsigned>(std::time(0)));
  Base *a = generate();
  Base *b = generate();
  Base *c = generate();

  a->identify(*a);
  b->identify(*b);
  c->identify(*c);
  a->identify(a);
  b->identify(b);
  c->identify(c);

  delete a;
  delete b;
  delete c;
}