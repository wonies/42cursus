#include <iostream>
#include <cstring>
using namespace std;


class X
{

private:
	int num;
public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum() const
	{
		return num;
	}
	void ShowNum() const{
		cout<<GetNum()<<endl;
	}
};



int main(void)
{

	return 0;
}