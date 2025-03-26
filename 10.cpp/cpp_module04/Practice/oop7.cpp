#include <iostream>

class First {
 public:
  virtual void myFunc() { std::cout << "First Func" << std::endl; }
};

class Second : public First {
 public:
  virtual void myFunc() { std::cout << "Second Func" << std::endl; }
};

class Third : public Second {
 public:
  virtual void myFunc() { std::cout << "Third Func" << std::endl; }
};

int main(void) {
  Third *tptr = new Third();
  Second *sptr = tptr;
  First *fptr = sptr;
  Second *sptr2 = new Second();

  fptr->myFunc();
  sptr->myFunc();
  tptr->myFunc();
  sptr2->myFunc();
  delete tptr;
  return 0;
}