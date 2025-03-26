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
  void moveForward() {
    cout << "차가 앞으로 전진합니다.." << endl;
  }  // 메서드 오버라이딩 -> 각각의 클래스의 맥락에 맞게 재정의 가능
  void moveBackward() {
    cout << "차가 뒤로 후진합니다..." << endl;
  }  // 같은 이름의 메서드가 상황에 따라 다른 역할을 수행함
  void openWindow() {
    cout << "모든 창문을 엽니다. " << endl;
  }  // 하나의 클래스에서 같은이름의 메서드를 여러개중복하여 정의하는 것을
     // 의미하는 메서드 오버로딩도 이와같은 맥락!

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

class Driver : public Car, public MotorBike {
 public:
  void drive(Car* car) {
    car->moveForward();
    car->moveBackward();
  }
  void drive(MotorBike* motorbike) {
    motorbike->moveForward();
    motorbike->moveBackward();
  }
};

int main(void) {
  Car* myCar = new Car();
  MotorBike* myBike = new MotorBike();
  Driver* driver = new Driver();

  driver->drive(myCar);
  driver->drive(myBike);

  delete myCar;
  //   delete myBike;
  return 0;
}

// 결합도가 매우 높은 코드
// 이동수단이 자동차,오토바이가 아닌 여러개라면? 코드를 여러번 작성해야함..
