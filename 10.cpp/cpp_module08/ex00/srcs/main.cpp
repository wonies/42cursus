#include "easyfind.hpp"

int main(void) {
  std::vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);

  // std::vector<int> arr = {1,2,3,4,5}; -> c++11 이상부터.
  try {
    int find;
    find = easyfind(arr, 3);
    std::cout << "find value: " << find << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    easyfind(arr, 7);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  /* 사실상 예시로 안해줘도 됨 */
  std::string characters = "wonie and konie";
  try {
    easyfind(characters, 'w');
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    easyfind(characters, 'q');
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}