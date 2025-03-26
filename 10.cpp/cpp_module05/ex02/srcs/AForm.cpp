#include "AForm.hpp"

AForm::AForm(void) {}

AForm::AForm(std::string name, unsigned int authorize, unsigned int execute)
    : _name(name), _sign(0), _authorize(authorize), _execute(execute) {}

AForm::AForm(AForm const &instance) { *this = instance; }

AForm &AForm::operator=(AForm const &rhs) {
  if (this != &rhs) {
    this->_sign = rhs._sign;
    this->_authorize = rhs._authorize;
    this->_execute = rhs._execute;
  }
  return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat &auth) {
  if (_authorize > 150)
    throw(AForm::GradeTooLowException());
  else if (_authorize < 1)
    throw(AForm::GradeTooHighException());
  if (_authorize > auth.getGrade())
    throw(AForm::GradeTooLowException());
  else {
    _sign = 1;
  }
}

std::string AForm::getName() const { return _name; }

bool AForm::getSign() const { return _sign; }

unsigned int AForm::getAuth() const { return _authorize; }

unsigned int AForm::getExecute() const { return _execute; }

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
  std::string answer;
  if (obj.getSign() > 0)
    answer = "YES";
  else
    answer = "NO";
  os << "AForm's Subject : " << obj.getName()
     << "\nAForm's authorize : " << answer
     << "\nAForm's authorized grade : " << obj.getAuth()
     << "\nAForm's executing grade : " << obj.getExecute() << std::endl;
  return os;
};