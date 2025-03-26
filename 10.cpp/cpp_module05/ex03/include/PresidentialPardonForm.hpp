#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm(void);
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm const &instance);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
  ~PresidentialPardonForm(void);
  bool execute(Bureaucrat const &exe) const;

 private:
};

#endif