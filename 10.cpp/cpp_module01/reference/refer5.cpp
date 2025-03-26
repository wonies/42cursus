#include <iostream>


void    SwapByPTR(int *ag1, int *ag2)
{
    int temp = *ag1;
    *ag1 = *ag2;
    *ag2 = temp;
}

void    SwapByRef(int &ag1, int &ag2)
{
    int temp = ag1;
    ag1 = ag2;
    ag2 = temp;
}

int main()
{
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;

    SwapByPTR(&num1, &num2);
    std::cout << num1 << " " << num2 << std::endl;
    SwapByRef(num3, num4);
    std::cout << num3 << " " << num4 << std::endl;
}