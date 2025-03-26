#include <iostream>

using namespace std;

int main(void)
{
    // const int num = 20;
    // int &ref = num;
    // ref += 10;

    // cout << num << endl;


    const int num = 20;
    const int &ref = num;
    // const int &ref = 50;

    cout << ref << endl;

}