#include <cstring>
#include <iostream>

using namespace std;

class Base {
 private:
 public:
  Base() { cout << "Base Constructor" << endl; }
  void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : public Base {
 public:
  MiddleDerivedOne() : Base() {
    cout << "Middle Derived One Constructor" << endl;
  }
  void MiddleFuncOne() {
    SimpleFunc();
    cout << "MiddleDerivedOne" << endl;
  }
};

class MiddleDerivedTwo : public Base {
 public:
  MiddleDerivedTwo() : Base() {
    cout << "Middle Derived TWo Constructor" << endl;
  }
  void MiddleFuncTwo() {
    SimpleFunc();
    cout << "MiddleDerivedTwo" << endl;
  }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {
 public:
  LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo() {
    cout << "LastDerived Constructor" << endl;
  }
  void Complex() {
    MiddleFuncOne();
    MiddleFuncTwo();
    MiddleDerivedOne::SimpleFunc();
  }
};

int main(void) {
  cout << "객체 생성 전 " << endl;
  LastDerived ldr;
  cout << "객체 생성 후 " << endl;
  ldr.Complex();
  return 0;
}