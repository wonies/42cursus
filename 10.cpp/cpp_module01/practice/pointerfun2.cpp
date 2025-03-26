#include <iostream>

using namespace std;

int	add(int a, int b)
{
	return (a + b);
}

void	print_odd(int a, int b, int (*f)(int, int)) //매개변수로 함수 add를 받음
{
	int	ret = f(a, b);

	if (ret % 2 == 1)
		cout << ret << endl;
	else
		cout << "홀수가 아니에요!" << endl;
}

int	main(void)
{
	print_odd(2, 4, add);
	print_odd(2, 3, add);
}
//출력
//홀수가 아니에요!
//5