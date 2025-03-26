#include <iostream>
using namespace std;

int main(void) {
  int num1, num2;
  cout << "enter the number : ";
  cin >> num1 >> num2;

  try {
    if (num2 == 0) throw num2;
    cout << "quote : " << num1 / num2 << endl;
    cout << "remainder : " << num1 % num2 << endl;
  } catch (int expn) {
    cout << "제수는 " << expn << "이 될 수 없음" << endl;
    cout << "프로그램을 다시 실행하세요" << endl;
  }
  cout << "end of main" << endl;
  return 0;
}
