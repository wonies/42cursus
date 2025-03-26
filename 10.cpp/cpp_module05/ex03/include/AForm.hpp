#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Form {
 public:
  Form(void);
  Form(std::string name, unsigned int authorize, unsigned int execute);
  Form(Form const &instance);
  Form &operator=(Form const &rhs);
  virtual ~Form(void);
  void beSigned(Bureaucrat &);
  virtual bool execute(Bureaucrat const &executor) const = 0;
  std::string getName() const;
  bool getSign() const;
  unsigned int getAuth() const;
  unsigned int getExecute() const;
  bool getProtect() const;
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Form Grade is too high";
    }
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Form Grade is too low"; }
  };

 private:
  const std::string _name;
  bool _sign;
  unsigned int _authorize;
  unsigned int _execute;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif