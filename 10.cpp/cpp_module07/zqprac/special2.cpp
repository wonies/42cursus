#include <cstring>
#include <iostream>
using namespace std;

template <typename T>

T Max(T a, T b) {
  return a > b ? a : b;
}
template <>
char *Max(char *a, char *b) {}
