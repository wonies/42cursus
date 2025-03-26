#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
    : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &instance)
    : AForm(getName(), 145, 137) {
  *this = instance;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  std::string fname = executor.getName() + "_shrubbery";
  std::ofstream outputFile(fname);

  if (!outputFile.is_open()) {
    std::cerr << "Can't not open file!" << std::endl;
    return 0;
  }
  if (executor.getGrade() <= 145 && executor.getGrade() <= 137) {
    outputFile << shrub_trees;

    std::cout << executor.getName() << " executed " << AForm::getName()
              << std::endl;
    return 1;
  } else {
    throw(Bureaucrat::GradeTooLowException());
    return 0;
  }
  outputFile.close();
}