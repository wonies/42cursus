#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n) : _size(n) {
  if (n == 0) {
    throw std::invalid_argument("Invalid size. Size must be greater than 0.");
  }
  _arr.reserve(n);
}

Span::Span(Span const &instance) { *this = instance; }

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    for (unsigned long i = 0; i <= _arr.size(); i++) {
      _arr[i] = rhs._arr[i];
    }
  }
  return *this;
}

Span::~Span(void) {}
void Span::addNumber(unsigned int n) {
  if (_arr.size() >= _size) throw std::runtime_error("size is over");
  std::vector<int>::iterator it;
  for (it = _arr.begin(); it != _arr.end(); it++) {
    if (*it == static_cast<int>(n)) throw std::runtime_error("already exist.");
  }
  _arr.push_back(n);
}

int Span::shortestSpan(void) {
  if ((_arr.empty()) || (_arr.size() == 1))
    throw std::runtime_error("can't find. array is empty");

  sort(_arr.begin(), _arr.end());
  std::vector<int> differences(_arr.size() - 1);
  std::adjacent_difference(_arr.begin(), _arr.end(), differences.begin());

  return *std::min_element(differences.begin(), differences.end());
}

int Span::longestSpan(void) {
  if ((_arr.empty()) || (_arr.size() == 1))
    throw std::runtime_error("can't find. array is empty");

  sort(_arr.begin(), _arr.end());
  int _end = _arr.back();
  int _begin = _arr.front();
  return _end - _begin;
}