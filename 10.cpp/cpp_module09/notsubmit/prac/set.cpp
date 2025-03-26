#include <iostream>
#include <set>

using namespace std;

template <typename C>
void dump(const char *desc, C c) {
  cout.width(12);
  cout << left << desc << "==> ";

  copy(c.begin(), c.end(), ostream_iterator<typename C::value_type>(cout, " "));
  cout << endl;
}

int main() {
  int ar[] = {1, 4, 8, 1, 9, 6, 3};

  int i;

  set<int> s;

  for (i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
    s.insert(ar[i]);
  }

  dump("원본", s);

  set<int> s2 = s;

  dump("사본", s2);

  const char *str = "ASDFASDFGHJKL";

  set<char> sc(&str[0], &str[13]);

  dump("문자셋", sc);
}