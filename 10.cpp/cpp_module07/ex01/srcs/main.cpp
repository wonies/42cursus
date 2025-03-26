#include <string>

#include "iter.hpp"

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  int arrLen = sizeof(arr) / sizeof(arr[0]);

  iter(arr, arrLen, swapElement<int>);
  std::cout << "\n-----------------------" << std::endl;
  iter<int>(arr, arrLen, swapElement);
  iter(arr, arrLen, countValue<int>);  // 반환형이 int일 때.

  printElement printer;  // 객체로 전달
  iter(arr, arrLen, printer);

  std::cout << "\n-------double------cast-----" << std::endl;
  double arrD[] = {2.0, 3.0, 9.0};
  unsigned int arrDlen = sizeof(arrD) / sizeof(arrD[0]);
  iter(arrD, arrDlen, swapElement);

  std::cout << "\n\n------string-------cast----" << std::endl;
  std::string arrS[] = {"wonie", "konie", "donie", "sonie", "jonie"};
  int arrSlen = sizeof(arrS) / sizeof(arrS[0]);

  iter(arrS, arrSlen, printer);

  std::cout << "\n------specialize template-----*const*---" << std::endl;

  int constArr[] = {1, 2, 3, 4, 5};
  int constArrLen = sizeof(constArr) / sizeof(constArr[0]);
  // iter(constArr, constArrLen, printer);
  iter(constArr, constArrLen, castConst<const int>);
  std::cout << "\n-------const & not const -----\n";
  iter(constArr, constArrLen, castConst<int>);
}
