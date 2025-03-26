#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class Pmerge {
 public:
  std::vector<int> _vector;
  std::deque<int> _deque;
  void pairsplit(void);
  void pairsort(int low, int high);
  // void mergeFjsort(int low, int high);
  int _size;
  std::vector<int> _mainchain;
  std::vector<int> _pending;
  std::vector<int> _sequence;
  void jacobsthal(int n);
  void pendtomain(void);
  void pair(int low, int high, int depth);
  void mainchain(void);
  void insertmain(int index);
  void jnum(void);

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif