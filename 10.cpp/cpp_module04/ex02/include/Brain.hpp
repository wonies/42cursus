#ifndef __BRAIN__H__
#define __BRAIN__H__

#include <iostream>

class Brain {
 public:
  std::string ideas[100];
  Brain(void);
  Brain(const Brain &instance);
  Brain &operator=(const Brain &rhs);
  ~Brain(void);
  std::string getContent(void) const;
  Brain(const std::string &idea);
  Brain &operator=(const std::string &str);
};

std::ostream &operator<<(std::ostream &os, const Brain &brain);
#endif