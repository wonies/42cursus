#include "Intern.hpp"

#include "Bureaucrat.hpp"

static const std::string formTypes[] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

Form *(Intern::*Intern::forms[3])(const std::string) = {
    &Intern::getShruberry, &Intern::getRobo, &Intern::getPardon};

Intern::Intern(void) {}

Intern::Intern(Intern const &instance) { *this = instance; }

Intern &Intern::operator=(const Intern &rhs) {
  if (this != &rhs) {
  }
  return *this;
}

Intern ::~Intern() {}

Form *Intern::makeForm(std::string formType, std::string target) {
  for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); ++i) {
    if (formType == formTypes[i]) {
      std::cout << "Intern creates " << formType << ㅎstd::endl;
      return (this->*forms[i])(target);
    }
  }
  std::cout << "Error: Unknown form type." << std::endl;
  return nullptr;
}

Form *Intern::getShruberry(const std::string fname) {
  return new ShrubberyCreationForm(fname);
}

Form *Intern::getRobo(const std::string fname) {
  return new RobotomyRequestForm(fname);
}

Form *Intern::getPardon(const std::string fname) {
  return new PresidentialPardonForm(fname);
}
