#include <iostream>
#include <cstring>
using namespace std;

class Cal
{
	public:
		void Init();
		double Add(double a, double b);
		double Div(double a, double b);
		double Min(double a, double b);
		double Mul(double a, double b);
		void	ShowOpCount();
	
	private:
		int add;
		int	minus;
		int multi;
		int divide;
};


void Cal::Init()
{
	add = 0;
	minus = 0;
	multi = 0;
	divide = 0;
}

double Cal::Add(double a, double b)
{
	double res;
	
	res = a + b;
	add++;
	return res;
}


double Cal::Min(double a, double b)
{
	double res;
	
	res = a - b;
	minus++;
	return res;
}

double Cal::Div(double a, double b)
{
	double res;
	
	res = a / b;
	divide++;
	return res;
}

double Cal::Mul(double a, double b)
{
	double res;
	
	res = a * b;
	multi++;
	return res;
}

void Cal::ShowOpCount()
{
	cout<<"Addition: "<<add<<endl;
	cout<<"Substraction: "<<minus<<endl;
	cout<<"Multiple: "<<multi<<endl;
	cout<<"Division: "<<divide<<endl;

}


int main(void)
{
	Cal cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.4 = "<<cal.Div(3.5, 1.4)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;


}