#include "AForm.hpp"

Form::Form(void) {}

Form::Form(std::string name, unsigned int authorize, unsigned int execute)
    : _name(name), _sign(0), _authorize(authorize), _execute(execute) {}

Form::Form(Form const &instance) { *this = instance; }

Form &Form::operator=(Form const &rhs) {
  if (this != &rhs) {
    this->_sign = rhs._sign;
    this->_authorize = rhs._authorize;
    this->_execute = rhs._execute;
  }
  return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat &auth) {
  if (_authorize > 150)
    throw(Form::GradeTooLowException());
  else if (_authorize < 1)
    throw(Form::GradeTooHighException());
  if (_authorize > auth.getGrade())
    throw(Form::GradeTooLowException());
  else {
    _sign = 1;
  }
}

std::string Form::getName() const { return _name; }

bool Form::getSign() const { return _sign; }

unsigned int Form::getAuth() const { return _authorize; }

unsigned int Form::getExecute() const { return _execute; }

std::ostream &operator<<(std::ostream &os, const Form &obj) {
  std::string answer;
  if (obj.getSign() > 0)
    answer = "YES";
  else
    answer = "NO";
  os << "Form's Subject : " << obj.getName()
     << "\nForm's authorize : " << answer
     << "\nForm's authorized grade : " << obj.getAuth()
     << "\nForm's executing grade : " << obj.getExecute() << std::endl;
  return os;
};