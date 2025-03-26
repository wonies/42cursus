#include <iostream>

class Car {
 private:
  std::string model;
  std::string color;
  void startEngine() { std::cout << "Start!" << std::endl; }
  void moveForward() { std::cout << "Go straight!" << std::endl; }
  void openWindow() { std::cout << "Open window!" << std::endl; }

 public:
  Car(std::string _model, std::string _color) : model(_model), color(_color) {}
  void operate() {
    startEngine();
    moveForward();
    openWindow();
  }
};

class Driver {
 private:
  std::string name;
  Car car;

 public:
  Driver(std::string _name, Car _car) : name(_name), car(_car) {}
  std::string getName() { return name; }
  void drive() { car.operate(); }
};

int main(void) {
  Car myCar("테슬라 X", "레드");
  Driver *driver = new Driver("워니", myCar);
  driver->drive();
}