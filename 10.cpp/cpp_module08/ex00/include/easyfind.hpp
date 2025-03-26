#ifndef EASY_HPP
#define EASY_HPP

#include <iostream>
#include <iterator>
#include <vector>

template <typename T>

int easyfind(T& container, int val) {
  typename T::iterator it = std::find(container.begin(), container.end(), val);

  if (it != container.end()) {
    std::cout << "Value Found at Index : "
              << std::distance(container.begin(), it) << std::endl;
  } else
    throw std::runtime_error("Not Found");
  return *it;  // 결과값의 주소를 역참조해서 결과값을 가르키고 있음
}

#endif