#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, int> m;

  m.insert(pair<string, int>(string("서울"), 1000));

  m.insert(pair<string, int>("부산", 500));

  m["대전"] = 400;

  m["대구"] = 300;

  m["광주"] = 200;

  m["인천"] = 100;

  m["독도"] = 1;

  m.erase(m.begin());

  m.erase("인천");

  map<string, int>::iterator it;

  for (it = m.begin(); it != m.end(); it++) {
    cout << it->first << ":" << it->second << "만명" << endl;
  }
}