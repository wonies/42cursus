#include "Array.hpp"

int main(void) {
  Array<int> arr(50);
  Array<double> arrDouble;
  Array<double> doublearr(29);
  Array<char> chararr(30);

  try {
    arr[20] = -1;
    std::cout << "arr [20]'s value : " << arr[20] << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    arr[-1] = 0;
    std::cout << "arr [-1]'s value : " << arr[20] << std::endl;

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    arr[50] = 9;
    std::cout << "arr [50]'s value : " << arr[50] << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    arrDouble[0] = 1.0;
    std::cout << "arr double's [0]'s value : " << arrDouble[0] << std::endl;

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    doublearr[10] = 2.0;
    std::cout << "arr double's [10]'s value : " << doublearr[10] << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    chararr[0] = 'w';
    std::cout << "char arr's [0]'s value : " << chararr[0] << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout
      << "\n\n----------------copy & allocate operator---------------\n\n";
  Array<int> copytest(arr);
  Array<char> alloctest = chararr;
  // Array<unsigned int> int_uint(arr); -> impossible!!

  std::cout << "copy result : " << copytest[20] << std::endl;
  std::cout << "allocate result : " << alloctest[0] << std::endl;

  alloctest[0] = 'k';
  std::cout << "\nalloc alert : " << alloctest[0] << std::endl;
  std::cout << "seperate exist<char> : " << chararr[0] << std::endl;

  copytest[20] = 99;
  std::cout << "\ncopy alert : " << copytest[20] << std::endl;
  std::cout << "seperate exist<int> : " << arr[20] << std::endl;

  std::cout << "\n\n----------size() member-function----------\n\n";
  std::cout << "arr's size : " << arr.size() << std::endl;
  std::cout << "char arr's size : " << alloctest.size() << std::endl;
}

// #define MAX_VAL 750
// int main(int, char**) {
//   Array<int> numbers(MAX_VAL);
//   int* mirror = new int[MAX_VAL];
//   srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     numbers[i] = value;
//     mirror[i] = value;
//   }
//   // SCOPE
//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     std::cout << "err"
//               << "\n";
//     numbers[-2] = 0;
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     std::cout << numbers[MAX_VAL - 1] << "\n";
//     numbers[MAX_VAL] = 0;
//   } catch (const std::exception& e) {
//     std::cerr << e.what() << '\n';
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }
//   delete[] mirror;
//   return 0;
// }
