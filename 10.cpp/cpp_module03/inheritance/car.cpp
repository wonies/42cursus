#include <iostream>

class Car {
 private:
  int gasolineG;

 public:
  Car() : gasolineG(40) {}
  int getGasGuage() { return gasolineG; }
};

class HybridCar : public Car {
 private:
  int electricG;

 public:
  HybridCar() : electricG(30) {}
  int getElecGuage() { return electricG; }
};

class HybridWater : public HybridCar {
 private:
  int waterG;

 public:
  HybridWater() : waterG(20) {}
  void showCurrentG() {
    std::cout << "잔여 가솔린 : " << getGasGuage() << std::endl;
    std::cout << "잔여 전기량 : " << getElecGuage() << std::endl;
    std::cout << "잔여 워터량 : " << waterG << std::endl;
  }
};

int main(void) {
  HybridWater hb;

  hb.showCurrentG();

  return 0;
}