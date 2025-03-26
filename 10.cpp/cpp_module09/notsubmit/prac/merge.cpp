#include <iostream>
#include <vector>
void mergesort(std::vector<long long> &origin, int low, int high) {
  int lside = high - low + 1;
  int rside = high - start;

  std::vector<long long> larr(lside);
  std::vector<long long> rarr(rside);
  for (int i = 0; i < lside; i++) {
    larr[i] = origin[low + i];
  }
  for (int i = 0; i < rside; i++) {
    rarr[i] = origin[mid + 1 + i];
  }
  for (int i = 0; i < lside; i++) std::cout << larr[i] << " ";
  std::cout << std::endl;
  for (int i = 0; i < rside; i++) std::cout << rarr[i] << " ";
  std::cout << std::endl;

  int i = 0;
  int j = 0;
  int k = low;

  while (i < lside && j < rside) {
    if (larr[i] <= rarr[j]) {
      origin[k++] = larr[i++];
    } else
      origin[k++] = rarr[j++];
  }
  while (i < lside) origin[k++] = larr[i++];
  while (j < rside) origin[k++] = rarr[j++];
}

void merge(std::vector<long long> &origin, int start, int end) {
  int mid = start + (end - low) / 2;
  if (start < end) {
    mergesort(origin, )
  }
}

int main(void) {
  std::vector<long long> origin = {27, 10, 12, 20, 25, 13, 15, 22};
  mergesort(origin, 0, 7);
  for (int i = 0; i < origin.size(); i++) {
    std::cout << origin[i] << " ";
  }
}

// g++ -std=c++11 sort.cpp -o sort
