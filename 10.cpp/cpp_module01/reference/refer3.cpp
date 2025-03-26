#include <iostream>

int main(void)
{
    const int num = 10;
    // int &ref = num;
    const int &ref2 = num;
    const int &ref3 = 100;

    std::cout << num << std::endl;
    std::cout << ref2 << std::endl;
    std::cout << ref3 << std::endl;
    
}