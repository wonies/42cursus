#include <iostream>

using namespace std;

void swap(int &ref1, int &ref2)
{
    int temp;

    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}



int main(void)
{
    int val1 = 10;
    int val2 = 20;
    swap(val1, val2);
    cout << "val1: "<<val1<<endl;
    cout << "val2: "<<val2<<endl;
    return 0;
}