#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
    : Form(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &instance)
    : Form(getName(), 72, 45) {
  *this = instance;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  std::srand(std::time(nullptr));

  int randomValue = std::rand() % 2;

  if (executor.getGrade() <= 72 && executor.getGrade() <= 45) {
    std::cout << "Drill........." << std::endl;
    std::cout << "Drill........." << std::endl;
    std::cout << executor.getName() << " has been robotomized  by "
              << Form::getName() << std::endl;
    sleep(1);
    if (randomValue == 0) {
      std::cout << "[50% 확률로] 로보토미 작업에 실패했습니다." << std::endl;
    } else {
      std::cout << "[50% 확률로] 로보토미 작업이 성공적으로 완료되었습니다."
                << std::endl;
      return 1;
    }
  } else {
    throw(Bureaucrat::GradeTooLowException());
    return 0;
  }
  return 0;
}