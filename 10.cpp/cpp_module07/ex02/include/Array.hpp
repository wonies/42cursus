#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
 public:
  Array(void) : _arr(new T[0]), _n(0) {}
  Array(unsigned int n) : _n(n) { _arr = new T[n]; }
  Array(Array const &instance) : _arr(new T[instance._n]), _n(instance._n) {
    *this = instance;
  }
  Array &operator=(Array const &rhs) {
    if (this != &rhs) {
      delete[] _arr;
      _n = rhs._n;
      _arr = new T[rhs._n];
      for (unsigned int i = 0; i < _n; i++) _arr[i] = rhs._arr[i];
    }
    return *this;
  }
  ~Array(void) { delete[] _arr; }
  T &operator[](unsigned int val) {
    if (val >= _n || val < 0) throw std::out_of_range("Index : out of range");
    return _arr[val];
  }
  int size() { return _n; }

 private:
  T *_arr;
  unsigned int _n;
};

#endif