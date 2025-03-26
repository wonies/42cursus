#ifndef MUSTACK_HPP
#define MUSTACK_HPP

#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(void){};
  MutantStack(MutantStack const &instance) { *this = instance; }
  MutantStack &operator=(MutantStack const &rhs) {
    if (this != &rhs) {
    }
    return *this;
  };
  ~MutantStack(void){};

  typename std::deque<T>::iterator begin() { return this->c.begin(); }
  typename std::deque<T>::iterator end() { return this->c.end(); }
  // typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::deque<T>::iterator iterator;

 private:
};

#endif