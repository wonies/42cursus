#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "\033[0;32m*Brain 생성자*\033[0;30m" << std::endl;
}

Brain::Brain(const Brain &instance) { *this = instance; }
Brain &Brain::operator=(const Brain &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < 100; i++) ideas[i] = rhs.ideas[i];
  }
  return (*this);
}
Brain::~Brain() {
  std::cout << "\033[0;32m~Brain 소멸자~\033[0;30m" << std::endl;
}
Brain &Brain::operator=(const std::string &str) {
  for (int i = 0; i < 100; i++) ideas[i] = str;
  return *this;
}

Brain::Brain(const std::string &idea) {
  for (int i = 0; i < 100; i++) ideas[i] = idea[i];
}

std::string Brain::getContent(void) const { return ideas[1]; }

std::ostream &operator<<(std::ostream &os, const Brain &brain) {
  os << brain.getContent();
  return os;
}