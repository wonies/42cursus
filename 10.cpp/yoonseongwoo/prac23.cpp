#include <iostream>
#include <cstring>
using namespace std;


class Printer
{

private:
	char	*res;
public:
	void	SetString(const char *s);
	void	ShowString();
};

void	Printer::SetString(const char *s)
{
	strcpy(res, s);
}

void	Printer::ShowString()
{
	cout<<res<<endl;
}



int main(void)
{
	Printer pnt;
	pnt.SetString("hello, world!");
	pnt.ShowString();

	pnt.SetString("We love c++");
	pnt.ShowString();

	return 0;
}