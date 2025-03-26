#include <iostream>

// template <class T1, class T2>

// struct pair {
//   typedef T1 first_type;

//   typedef T2 second_type;

//   T1 first;

//   T2 second;

//   pair() : first(T1()), second(T2()) {}

//   pair(const T1& v1, const T2& v2) : first(v1), second(v2) {}
// };

#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<string, double> sdpair;

sdpair GetPair() {
  sdpair temp;

  temp.first = "문자열";

  temp.second = 1.234;

  return temp;

  // return make_pair("문자열",1.234);
}

int main() {
  sdpair SD;

  SD = GetPair();

  cout << SD.first << "," << SD.second << endl;
}