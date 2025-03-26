#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Bureaucrat;
class Form;
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern(void);
  Intern(Intern const &instance);
  Intern &operator=(Intern const &rhs);
  ~Intern(void);
  Form *makeForm(std::string request, std::string target);
  Form *getShruberry(const std::string fname);
  Form *getRobo(const std::string fname);
  Form *getPardon(const std::string fname);
  static Form *(Intern::*forms[3])(const std::string);

 private:
};

#endif