#include <iostream>
#include <vector>

//  Binary Insertion Sort를 사용한 정렬된 배열 병합
std::vector<int> binaryInsertionSortMerge(const std::vector<int>& arr1,
                                          const std::vector<int>& arr2) {
  std::vector<int> result;
  result.reserve(arr1.size() + arr2.size());

  // 첫 번째 배열 복사
  for (int num : arr1) {
    result.push_back(num);
  }

  // 두 번째 배열 요소를 이진 삽입 정렬로 삽입
  for (int num : arr2) {
    auto it = std::upper_bound(result.begin(), result.end(), num);
    result.insert(it, num);
  }

  return result;
}

// Two-way merging을 사용한 정렬된 배열 병합
std::vector<int> twoWayMerge(const std::vector<int>& arr1,
                             const std::vector<int>& arr2) {
  std::vector<int> result;
  result.reserve(arr1.size() + arr2.size());

  // 인덱스
  int i = 0, j = 0;

  // 두 배열을 비교하면서 작은 값을 결과에 추가
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] <= arr2[j]) {
      result.push_back(arr1[i]);
      i++;
    } else {
      result.push_back(arr2[j]);
      j++;
    }
  }

  // 남은 요소들 추가
  while (i < arr1.size()) {
    result.push_back(arr1[i]);
    i++;
  }
  while (j < arr2.size()) {
    result.push_back(arr2[j]);
    j++;
  }

  return result;
}

int main() {
  std::vector<int> arr1 = {1, 3, 5, 7, 9};
  std::vector<int> arr2 = {2, 4, 6, 8, 10};

  // 이진 삽입 정렬로 정렬된 배열 병합
  std::vector<int> merged1 = binaryInsertionSortMerge(arr1, arr2);
  std::cout << "Merged array using binary insertion sort merge: ";
  for (int num : merged1) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Two-way merging으로 정렬된 배열 병합
  std::vector<int> merged2 = twoWayMerge(arr1, arr2);
  std::cout << "Merged array using two-way merge: ";
  for (int num : merged2) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
