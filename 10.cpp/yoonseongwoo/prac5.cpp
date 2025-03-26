#include <iostream>

using namespace std;

int main(void)
{
    int num1 = 2010;
    int &num2 = num1;

    num2 = 3047;
    cout<<"val: "<<num1<<endl;
    cout<<"ref: "<<num2<<endl;

    cout<<"val: "<<&num1<<endl;
    cout<<"ref: "<<&num2<<endl; 
}

/* 
참조자는 별칭이다.
->변수에 별명을 하나붙여주는 것을 의미
*/