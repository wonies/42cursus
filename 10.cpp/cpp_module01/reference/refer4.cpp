#include <iostream>

int Add(const int &num1, const int &num2)
{
    return num1 + num2;
}


int Add(int &num1, int &num2)
{
    return num1 + num2;
}


int main(void)
{
    std::cout << Add(1, 2) << std::endl;

    return 0;
}