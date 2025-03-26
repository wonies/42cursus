#include <deque>
#include <iostream>
#include <utility>
#include <vector>
std::vector<std::pair<int, int> > _vec;

void comparesort(int left, int mid, int right) {
  std::vector<std::pair<int, int> > _n1(mid - left + 1);
  std::vector<std::pair<int, int> > _n2(right - mid);

  // 데이터 복사
  for (int i = 0; i < _n1.size(); i++) {
    _n1[i] = _vec[left + i];
  }
  for (int i = 0; i < _n2.size(); i++) {
    _n2[i] = _vec[mid + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = left;
  while (i < _n1.size() && j < _n2.size()) {
    if (_n1[i].first <= _n2[j].first) {
      _vec[k] = _n1[i];
      i++;
    } else {
      _vec[k] = _n2[j];
      j++;
    }
    k++;
  }

  // 남은 요소들을 _vec에 복사
  while (i < _n1.size()) {
    _vec[k] = _n1[i];
    i++;
    k++;
  }
  while (j < _n2.size()) {
    _vec[k] = _n2[j];
    j++;
    k++;
  }
}

void sortpair(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortpair(left, mid);
    sortpair(mid + 1, right);
    comparesort(left, mid, right);
  }
}
int main(void) {
  //   std::vector<std::pair<int, int> > _vec;
  _vec.push_back(std::make_pair(3, 8));
  _vec.push_back(std::make_pair(1, 9));
  _vec.push_back(std::make_pair(2, 0));
  _vec.push_back(std::make_pair(7, 4));
  _vec.push_back(std::make_pair(11, 12));

  sortpair(0, 4);
  for (int i = 0; i < 5; i++)
    std::cout << "sorted first : " << _vec[i].first
              << "sorted second : " << _vec[i].second << "\n";
}