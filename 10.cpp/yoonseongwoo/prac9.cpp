#include <iostream>

using namespace std;

void swap(int *(&ref1), int *(&ref2))
{
    int *temp;

    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}



int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;

    int num2 = 10;
    int *ptr2 = &num2;
    
    cout << "val1: "<<ptr1<<endl;
    cout << "val2: "<<ptr2<<endl;

    ptr1 = &num1;
    ptr2 = &num2;
    
    swap(ptr1, ptr2);

    cout << "val1: "<<ptr1<<endl;
    cout << "val2: "<<ptr2<<endl;

    cout << "val1: "<<num1<<endl;
    cout << "val2: "<<num2<<endl;
    return 0;
}