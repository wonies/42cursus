#include <iostream>
#include <vector>

void mergesort(std::vector<long long>& origin, int low, int mid, int high) {
  if (low >= high) return;
  std::vector<long long> larr(mid - low + 1);
  std::vector<long long> rarr(high - mid);

  std::cout << "depth" << std::endl;
  for (int i = 0; i < larr.size(); i++) {
    larr[i] = origin[low + i];
    std::cout << "left arr : " << larr[i] << std::endl;
  }
  for (int i = 0; i < rarr.size(); i++) {
    rarr[i] = origin[mid + 1 + i];
    std::cout << "right arr : " << rarr[i] << std::endl;
  }

  int i = 0;
  int j = 0;
  int k = low;

  while (i < larr.size() && j < rarr.size()) {
    if (larr[i] <= rarr[j])
      origin[k++] = larr[i++];
    else
      origin[k++] = rarr[j++];
  }
  while (i < larr.size()) origin[k++] = larr[i++];
  while (j < rarr.size()) origin[k++] = rarr[j++];
}

void merge(std::vector<long long>& origin, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    std::cout << "mid : " << mid << std::endl;
    merge(origin, low, mid);
    merge(origin, mid + 1, high);
    mergesort(origin, low, mid, high);
  }
}

int main(void) {
  std::vector<long long> origin = {27, 10, 12, 20, 25, 13, 15, 22};
  merge(origin, 0, 7);
  for (int i = 0; i < 8; i++)
    std::cout << "origin : " << origin[i] << std::endl;
}
