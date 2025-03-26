#include <iostream>

using namespace std;


int    &reffun(int &ref)
{
    ref++;
    return ref;
}

int new_reffun(int &ref)
{
    ref++;
    return ref;
}


int main(void)
{
    int num1 = 1;
    int &num2 = reffun(num1);
    int num3 = reffun(num1);
    
    num1*=2;
    num2*=2;
    num3*=2;
    cout<<"num1 : "<<num1<<endl;
    cout<<"num2 : "<<num2<<endl;
    cout<<"num3 : "<<num3<<endl;

    int new_num = 1;
    int new_num2 = new_reffun(new_num);

    new_num++;
    new_num2 *= 20;

    cout<<"new num1 : "<<new_num<<endl;
    cout<<"new num2 : "<<new_num2<<endl;


    return 0;
    
}