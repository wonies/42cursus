#include <iostream>
#include <cstring>
using namespace std;


class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	int SaleApples(int money)
	{
		int num = money/APPLE_PRICE;
		numOfApples -= num;
		myMoney+=money;
		return num;
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesRes()
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl;
	}
};



int main(void)
{


	return 0;
}