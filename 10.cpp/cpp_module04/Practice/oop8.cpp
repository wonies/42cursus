#include <iostream>
using namespace std;

class First {
 private:
  char *strone;

 public:
  First(char *str) { strone = new char[strlen(str) + 1]; }
  virtual ~First() {
    cout << "~First" << endl;
    delete[] strone;
  }
};

class Second : public First {
 private:
  char *strtwo;

 public:
  Second(char *str1, char *str2) : First(str1) {
    strtwo = new char[strlen(str2) + 1];
  }
  ~Second() {
    cout << "~Second" << endl;
    delete[] strtwo;
  }
};

void leak() { system("leaks a.out"); }

int main(void) {
  First *ptr = new Second("simple", "complex");
  delete ptr;
  leak();
  return 0;
}