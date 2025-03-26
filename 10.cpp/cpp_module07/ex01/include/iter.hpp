#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

//-------------기본형 template [non-const] vs [const]

template <typename T1>

void iter(T1 *adr, size_t len, void (*f)(T1 &)) {
  for (size_t i = 0; i < len; i++) f(adr[i]);
}

template <typename T1>
void iter(const T1 *adr, const size_t len, void (*f)(const T1 &)) {
  for (size_t i = 0; i < len; i++) f(adr[i]);
}

//------------------[함수1]--------------------
struct printElement {
  template <typename T>
  void operator()(const T &element) const {
    std::cout << "Print : " << element << std::endl;
  }
  template <typename T>

  void operator()(T &element) const {
    std::cout << "Print : " << element << std::endl;
  }
};

//-----------------[함수2]---------------------
template <typename T1>

void swapElement(T1 &a) {
  a += 1;
  std::cout << a << " ";
}

//---------------[함수3]--------------------
template <typename T1>

int countValue(T1 &a) {
  int len = sizeof(a) / 4;
  int cnt = 0;
  for (int i = 0; i < len; i++) cnt += a;
  return cnt;
}

// -----------[함수4]-----------------------
template <typename T1>

void multiple(T1 &a) {
  a *= a;
}

//--------[함수5 / const 함수]--------------
template <typename T1>

void castConst(T1 &a) {
  // int b = const_cast<int &>(a);
  // b *= 3; -> possible!
  std::cout << "<const> : " << a << " ";
}

//---------추가적인 template : 객체로 불러오는 방법, 이럴 땐 꼭 T2로.
template <typename T1, typename T2>

void iter(T1 *adr, size_t len, T2 &f) {
  for (size_t i = 0; i < len; i++) f(adr[i]);
}

// -----------[countValue]-----------------
template <typename T1, typename T2>
void iter(T1 *adr, size_t len, T2 (*f)(T1 &)) {
  // for (size_t i = 0; i < len; i++) f(adr[i]);
  int res = 0;
  for (size_t i = 0; i < len; i++) res += f(adr[i]);
  std::cout << "\n***res*** : " << res << std::endl;
}

#endif