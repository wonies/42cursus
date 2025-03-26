#include <cstring>
#include <iostream>

class SoBase {
 private:
  int baseNum;

 public:
  SoBase() : baseNum(20) { std::cout << "SoBase()" << std::endl; }
  SoBase(int n) : baseNum(n) { std::cout << "SoBase(int n)" << std::endl; }
  void ShowBaseData() { std::cout << baseNum << std::endl; }
  ~SoBase() { std::cout << "decrep BASE()  " << baseNum << std::endl; }
};

class SoDerived : public SoBase {
 private:
  int deriveNum;

 public:
  SoDerived() : deriveNum(30) { std::cout << "soDerived()" << std::endl; }
  SoDerived(int n) : deriveNum(n) {
    std::cout << "soDerived(int n)" << std::endl;
  }
  SoDerived(int n1, int n2) : SoBase(n1), deriveNum(n2) {
    std::cout << "SoDerived(int n1, int n2)" << std::endl;
  }
  void ShowDerivedData() {
    ShowBaseData();
    std::cout << deriveNum << std::endl;
  }
  ~SoDerived() { std::cout << "decrep Derived()   " << deriveNum << std::endl; }
};

int main(void) {
  std::cout << "case1 ..... " << std::endl;
  SoDerived dr1;
  dr1.ShowDerivedData();
  std::cout << "----------------------" << std::endl;
  std::cout << "case2 ..... " << std::endl;
  SoDerived dr2(12);
  dr2.ShowDerivedData();
  std::cout << "----------------------" << std::endl;
  std::cout << "case3 ..... " << std::endl;
  SoDerived dr3(23, 24);
  dr3.ShowDerivedData();
  std::cout << "----------------------" << std::endl;
}