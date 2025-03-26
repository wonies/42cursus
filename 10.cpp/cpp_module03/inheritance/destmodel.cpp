#include <cstring>
#include <iostream>

class Person {
 private:
  std::string name;

 public:
  Person(std::string _name) { name = _name; }
  ~Person() { std::cout << "Edge of the ... " << name << std::endl; }
  void WhatYourName() const {
    std::cout << "my name is..." << name << std::endl;
  }
};

class UnivStudent : public Person {
 private:
  std::string major;

 public:
  UnivStudent(std::string _name, std::string _major) : Person(_name) {
    major = _major;
  }
  ~UnivStudent() { std::cout << "The edge of the ... " << major << std::endl; }
  void WhoAreU() const {
    WhatYourName();
    std::cout << "my major is ... " << major << std::endl << std::endl;
  }
};

int main(void) {
  UnivStudent stu1("wonie", "Computer Science");
  stu1.WhoAreU();
  UnivStudent stu2("konie", "Math");
  stu2.WhoAreU();

  return 0;
}