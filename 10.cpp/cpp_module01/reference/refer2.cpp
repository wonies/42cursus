#include <iostream>

int main(void)
{
    int num = 1;
    int num2 = 2;

    int &ref = num;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;

    ref = num2;

    std::cout << &num2 << std::endl;
    std::cout << &num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
}
