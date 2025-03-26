#include <algorithm>
#include <iostream>
#include <vector>

// Insertion sort를 사용하여 배열을 정렬하는 함수
void insertion_sort(std::vector<int>& arr) {
  for (int i = 1; i < arr.size(); ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// 두 부분 배열을 병합하는 함수
void merge(std::vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

// Merge-insertion 정렬 알고리즘
void merge_insertion_sort(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    if (right - left < 5) {  // 배열 크기가 작을 때 insertion sort 사용
      insertion_sort(arr);
    } else {
      int mid = left + (right - left) / 2;
      merge_insertion_sort(arr, left, mid);
      merge_insertion_sort(arr, mid + 1, right);
      merge(arr, left, mid, right);
    }
  }
}

int main() {
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  int n = arr.size();

  std::cout << "원래 배열: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  merge_insertion_sort(arr, 0, n - 1);

  std::cout << "정렬된 배열: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}