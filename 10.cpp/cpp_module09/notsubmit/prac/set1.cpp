#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> s;

  s.insert(1);

  s.insert(2);

  s.insert(3);

  set<int>::iterator it;

  it = s.find(2);

  if (it != s.end()) {
    cout << *it << endl;

  } else {
    cout << "찾는 키가 없습니다." << endl;
  }
}