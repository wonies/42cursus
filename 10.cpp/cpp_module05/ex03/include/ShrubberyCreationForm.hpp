#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>

#include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string document);
  ShrubberyCreationForm(ShrubberyCreationForm const &instance);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
  ~ShrubberyCreationForm(void);
  bool execute(Bureaucrat const &exe) const;

 private:
};

#define shrub_trees            \
  "         *          \n"     \
  "        /|\\         \n"    \
  "       /*|O\\        \n"    \
  "      /*/|\\*\\       \n"   \
  "     /X/O|*\\X\\      \n"   \
  "    /*/X/|\\X\\*\\     \n"  \
  "   /O/*/X|*\\O\\X\\    \n"  \
  "  /*/O/X/|\\X\\O\\*\\   \n" \
  " /X/O/*/X|*\\O\\X\\\\  \n"  \
  "/O/X/*/O/|\\X\\*O\\\\ \n"   \
  "/O/X/*/O/X/|\\X\\O\\X\\ \n" \
  "       |X|          \n"     \
  "       |X|          \n"     \
  "       |X|          \n"     \
  "   ____|X|____   \n";

#endif