#include <iostream>

class Person {
 private:
  int age;
  char *name[50];

 public:
  Person(int _age, char *_name) : age(_age) { strcpy(name, _name); }
  void WhatYourName() const { std::cout << "My name is " << name << std::endl; }
  void HowOldAreU() const {
    std::cout << "I'm " << age << " years OLD " << std::endl;
  }
};

class UnivStudent : public Person {
 private:
  char *major[50];

 public:
  UnivStudent(char *_name, int _age, char *_major) : Person(_age, _name) {
    strcpy(major, _major);
  }
  void WhoAreU() const {
    WhatYourName();
    HowOldAreU();
    std::cout << "my major is... " << major << std::endl << std::endl;
  }
};

int main() {
  Person student1(20, "wonie");

  student1.WhatYourName();
  student1.HowOldAreU();
  UnivStudent Uni_stu1("konie", 22, "computer science");
  Uni_stu1.WhoAreU();
}