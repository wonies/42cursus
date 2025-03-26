#include <iostream>

class Car {
 private:
  int fuelGuage;

 public:
  Car(int fuel) : fuelGuage(fuel) {}
  void ShowCarState() { std::cout << "remainder : " << fuelGuage << std::endl; }
};

class Truck : public Car {
 private:
  int freightWeight;

 public:
  Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) {}
  void ShowTruckState() {
    ShowCarState();
    std::cout << "the weight of Freight : " << freightWeight << std::endl;
  }
};

int main(void) {
  Car *pcar = new Truck(80, 200);
  Truck *ptruck = static_cast<Truck *>(pcar);
  ptruck->ShowTruckState();
  std::cout << std::endl;  // 컴파일 성공

  Car *pcar2 = new Car(120);
  Truck *ptruck2 = static_cast<Truck *>(pcar2);
  ptruck2->ShowTruckState();  // 컴파일은 되나 값이 이상하게 나옴..
  return 0;
}