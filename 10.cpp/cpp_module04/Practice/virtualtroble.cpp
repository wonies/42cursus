#include <iostream>

class Base {
 public:
  virtual void virtualFunction() = 0;
  virtual ~Base() { virtualFunction(); }
};

class Derived : public Base {
 public:
  void virtualFunction() { std::cout << "Derived version\n"; }
  ~Derived() {}
};

int main() {
  Base* obj = new Derived();
  delete obj;
}
