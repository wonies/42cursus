#include <iostream>
using namespace std;

void SimpleOne(void);
void SimpleTwo(void);
void SimpleThree(void);

int main(void) {
  try {
    SimpleOne();
  } catch (int8_t expn) {
    cout << "exception: " << expn << endl;
  }
  return 0;
}

void SimpleOne(void) {
  cout << "SimpleOne(void)" << endl;
  SimpleTwo();
}

void SimpleTwo(void) {
  cout << "SimpleTwo(void)" << endl;
  SimpleThree();
}

void SimpleThree(void) {
  cout << "SimpleThree(void)" << endl;
  throw -1;
}