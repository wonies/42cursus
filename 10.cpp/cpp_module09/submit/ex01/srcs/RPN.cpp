#include "RPN.hpp"
RPN::~RPN(void) {}

RPN::RPN(void) {}

bool RPN::err(std::string input) {
  int ccnt = 0;
  int ncnt = 0;
  try {
    for (size_t i = 0; i < input.length(); i++) {
      char c = input[i];
      if (!((c >= '0' && c <= '9') ||
            (c == '+' || c == '-' || c == '*' || c == '/' || c == ' '))) {
        throw std::out_of_range("Error");
      } else if (c >= '0' && c <= '9') {
        ccnt++;
      } else if (c == '+' || c == '-' || c == '*' || c == '/')
        ncnt++;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return false;
  }
  if (ccnt - 1 != ncnt) {
    std::cout << "Error: can't calculate\n";
    return false;
  }
  return true;
}

bool RPN::enter(std::string input) {
  if (!err(input)) return false;
  std::stack<int> _stack;
  int value = 0;
  if (input.length() == 1) {
    std::cout << input << std::endl;
    return false;
  }
  for (size_t i = 0; i < input.length(); i++) {
    char c = input[i];
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (_stack.size() < 2) {
        std::cerr << "Error\n";
        return false;
      }

      int operandL = _stack.top();
      _stack.pop();
      int operandR = _stack.top();
      _stack.pop();
      if (c == '+')
        value = operandL + operandR;
      else if (c == '*')
        value = operandL * operandR;
      else if (c == '-')
        value = operandR - operandL;
      else if (c == '/') {
        if (operandL == 0) {
          std::cerr << "can't devided by zero\n";
          return false;
        }
        value = operandR / operandL;
      }
      _stack.push(value);
    } else if (c >= '0' && c <= '9') {
      _stack.push(c - '0');
    }
  }
  std::cout << value << std::endl;
  // while (!_stack.empty()) {
  //   int topValue = _stack.top();
  //   _stack.pop();
  //   std::cout << "stack : " << topValue << std::endl;
  // }
  return true;
}