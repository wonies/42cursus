#include <iostream>

using namespace std;

int	add(int a, int b)
{
	return (a + b);
}

int	main(void)
{
	int	(*f)(int, int);

	f = add; // 함수 add를 함수 포인터 f에 저장.

	cout << f(1, 2) << endl;
}