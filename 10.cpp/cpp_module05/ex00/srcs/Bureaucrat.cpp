#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : _name(name) {
  if (grade < 1)
    throw(Bureaucrat::GradeTooHighException());
  else if (grade > 150)
    throw(Bureaucrat::GradeTooLowException());
  _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance) { *this = instance; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    this->_grade = rhs._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const { return _name; }

unsigned int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::setUpGrade(void) {
  this->_grade--;
  if (_grade < 1) throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::setDownGrade(void) {
  this->_grade++;
  if (_grade > 150) throw(Bureaucrat::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return os;
};