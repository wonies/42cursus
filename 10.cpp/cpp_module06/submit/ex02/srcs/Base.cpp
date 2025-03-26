#include "Base.hpp"

Base::~Base(void) {}

Base *generate(void) {
  int value = std::rand() % 3;
  std::cout << "value " << value << std::endl;
  if (value == 0)
    return new A();
  else if (value == 1)
    return new B();
  else
    return new C();
}

void Base::identify(Base *p) {
  std::cout << "---*---" << std::endl;
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "CANT IDENTIFY" << std::endl;
}

void Base::identify(Base &p) {
  std::cout << "---&---" << std::endl;

  try {
    A aa = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    (void)aa;
  } catch (const std::exception &e) {
    std::cout << "CANT IDENTIFY" << std::endl;
  }
  try {
    B bb = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    (void)bb;
  } catch (const std::exception &e) {
    std::cout << "CANT IDENTIFY" << std::endl;
  }
  try {
    C cc = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    (void)cc;

  } catch (const std::exception &e) {
    std::cout << "CANT IDENTIFY" << std::endl;
  }
}
