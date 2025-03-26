#include "Bureaucrat.hpp"

void test1(void);
void test2(void);
void test3(void);

int main(void) {
  test1();
  test2();
  test3();

  return 0;
}

void test1(void) {
  try {
    Bureaucrat officer("wonie", 0);
    std::cout << officer << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test2(void) {
  Bureaucrat officer("konie", 10);
  try {
    std::cout << officer << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test3(void) {
  Bureaucrat officer("monie", 149);
  try {
    officer.setDownGrade();
    officer.setDownGrade();
    std::cout << officer << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
