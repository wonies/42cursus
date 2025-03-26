#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <unistd.h>

#include <ctime>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string robo);
  RobotomyRequestForm(RobotomyRequestForm const &instance);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
  ~RobotomyRequestForm(void);
  bool execute(Bureaucrat const &exe) const;

 private:
};

#endif