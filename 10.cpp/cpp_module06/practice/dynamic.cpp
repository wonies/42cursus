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
  //   Car *pcar = new Truck(80, 200);
  //   Truck *ptruck = dynamic_cast<Truck *>(pcar);

  //   Car *pcar2 = new Car(120);
  //   Truck *ptruck2 = dynamic_cast<Truck *>(pcar);

  Truck *ptruck3 = new Truck(70, 150);
  Car *pcar3 = dynamic_cast<Car *>(ptruck3);
  return 0;
}