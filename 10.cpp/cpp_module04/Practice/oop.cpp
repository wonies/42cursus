#include <cstring>
#include <iostream>
using namespace std;

class Vehicle {
 public:
  //   virtual void startEngine() = 0;
  string company;
  string model;
  string color;
  int wheels;
  void startEngine() { cout << "vehicle start Engine" << endl; }
  virtual void moveForward() { cout << "앞으로 전진합니다." << endl; }
  virtual void moveBackward() { cout << "후진합니다. " << endl; }
  virtual ~Vehicle() {}
  // 다른 필요한 순수 가상 함수들...
};

class Car : public Vehicle {
 public:
  //   string company;
  //   string model;
  //   string color;
  //   int wheels;
  bool isConvertible;
  //   void startEngine() { cout << "시동을 겁니다." << endl; }
  //   void moveForward() { cout << "차가 앞으로 전진합니다.." << endl; }
  //   void moveBackward() { cout << "차가 뒤로 후진합니다..." << endl; }
  void openWindow() { cout << "모든 창문을 엽니다. " << endl; }

 private:
};

class MotorBike : public Vehicle {
 public:
  //   string company;
  //   string model;
  //   string color;
  //   int wheels;
  bool isRaceable;
  void startEngine() { cout << "시동을 겁니다." << endl; }
  void moveForward() { cout << "오토바이가 앞으로 전진합니다.." << endl; }
  //   void moveBackward() { cout << "오토바이가 뒤로 후진합니다..." << endl; }
  void stunt() { cout << "묘기를 부립니다." << endl; }

 private:
};

int main(void) {
  Car* myCar = new Car();
  MotorBike* myBike = new MotorBike();

  myCar->model = "테슬라";
  myCar->color = "RED";
  cout << "나의 자동차는 " << myCar->color << " " << myCar->model << "입니당.."
       << endl;

  myCar->startEngine();
  myCar->moveForward();
  myCar->moveBackward();
  myBike->startEngine();
  myBike->moveForward();
  myBike->moveBackward();
  delete myCar;
  //   delete myBike;
  return 0;
}