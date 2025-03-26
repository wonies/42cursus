#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <locale>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 public:
  RPN(void);
  ~RPN(void);
  bool enter(std::string input);
  bool err(std::string input);

 private:
  RPN(RPN const &instance);
  RPN &operator=(RPN const &rhs);
};

#endif