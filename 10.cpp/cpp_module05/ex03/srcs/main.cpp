#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1(void);
void test2(void);
void test3(void);
void test4(void);

int main(void) {
  test1();
  test2();
  test3();
  test4();

  return 0;
}

void test1(void) {
  try {
    Bureaucrat officer("wonie", 130);
    ShrubberyCreationForm shrub("슈루베리베리스트로베리");
    // shrub.excute(officer);
    officer.executeForm(shrub);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test2(void) {
  std::cout << "\n\n---------------test2-----------------\n\n";
  Bureaucrat officer("konie", 10);
  RobotomyRequestForm robo("코딩 자동화 정책");
  try {
    robo.execute(officer);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test3(void) {
  std::cout << "\n\n---------------test3-----------------\n\n";
  Bureaucrat officer("monie", 2);
  PresidentialPardonForm pardoner("광복절 특사");
  try {
    pardoner.execute(officer);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test4(void) {
  std::cout << "\n\n---------------test4-----------------\n\n";
  Intern someRandomIntern;
  Form* rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  delete rrf;
}