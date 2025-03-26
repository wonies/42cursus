#include <iostream>

using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dp = &ptr;

    int &ref = num;
    int *(&ptref) = ptr;
    int **(&dpref) = dp;

    cout<<ref<<endl;
    cout<<*ptref<<endl;
    cout<<**dpref<<endl;

    return 0;
}