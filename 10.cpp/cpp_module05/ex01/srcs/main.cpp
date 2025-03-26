#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    Bureaucrat officer("wonie", 1);
    Form form("주차 위반 건에 관하여", 5, 120);
    form.beSigned(officer);
    officer.signForm(form);
    std::cout << form << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test2(void) {
  Bureaucrat officer("konie", 10);
  Form form("식품 위반 건에 관하여", 3, 5);
  try {
    form.beSigned(officer);
    officer.signForm(form);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::cout << form << std::endl;
}

void test3(void) {
  try {
    Bureaucrat officer("monie", 149);
    Form form("도박 위반 건에 관하여", 130, 150);
    form.beSigned(officer);
    officer.signForm(form);
    officer.setDownGrade();
    officer.setDownGrade();
    std::cout << form << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
