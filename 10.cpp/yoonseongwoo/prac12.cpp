#include <iostream>

using namespace std;

int main(void)
{
    const int num = 12;
    const int  *ptr = &num;
    const int  *(&ptrref) = ptr;

    cout<<"num :"<<num<<endl;
    cout<<"ptr :"<< *ptr <<endl;
    cout<<"ptrref :"<<*ptrref<<endl;

}