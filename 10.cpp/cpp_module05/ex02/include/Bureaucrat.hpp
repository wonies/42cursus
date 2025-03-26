#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
 public:
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(Bureaucrat const &instance);
  Bureaucrat &operator=(Bureaucrat const &rhs);
  virtual ~Bureaucrat(void);
  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw() { return "Grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw() { return "Grade is too low"; }
  };
  std::string getName(void) const;
  unsigned int getGrade(void) const;
  void setUpGrade(void);
  void setDownGrade(void);
  void signForm(const AForm &forms);
  void executeForm(AForm const &form);

 private:
  Bureaucrat(void);
  const std::string _name;
  unsigned int _grade;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif