#include <iostream>

class Car {
 private:
  std::string model;
  std::string color;

 public:
  Car(std::string _model, std::string _color) : model(_model), color(_color) {}
  void startEngine() { std::cout << "Start!" << std::endl; }
  void moveForward() { std::cout << "Go straight!" << std::endl; }
  void openWindow() { std::cout << "Open window!" << std::endl; }
};

class Driver {
 private:
  std::string name;
  Car car;

 public:
  Driver(std::string _name, Car _car) : name(_name), car(_car) {}
  void drive() {
    car.startEngine();
    car.moveForward();
    car.openWindow();
  }
};

int main(void) {
  Car myCar("테슬라 X", "레드");
  Driver *driver = new Driver("워니", myCar);
  driver->drive();
}