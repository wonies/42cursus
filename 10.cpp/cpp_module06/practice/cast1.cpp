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
  Truck *ptruck = (Truck *)pcar;
  ptruck->ShowTruckState();
  std::cout << std::endl;
  Car *pcar2 = new Car(120);
  Truck *ptruck2 = (Truck *)pcar2;
  ptruck2->ShowTruckState();
  return 0;
}