#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
    : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& instance)
    : AForm(getName(), 25, 5) {
  *this = instance;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

bool PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() <= 25 && executor.getGrade() <= 5) {
    std::cout << executor.getName()
              << " has been pardoned by Zaphod Beeblebrox."
              << " (" << AForm::getName() << ")" << std::endl;
    return (1);
  } else
    throw(Bureaucrat::GradeTooLowException());
  return 0;
}