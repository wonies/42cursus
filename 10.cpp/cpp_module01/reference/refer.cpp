#include <iostream>

int main(void)
{
    int num = 1;
    int &ref = num;

    ref = 2;
    
    std::cout << "num value : " << num << std::endl;
    std::cout << "ref value : " << ref << std::endl;

    std::cout << "num add : " << &num << std::endl;
    std::cout << "ref add : " << &ref << std::endl;

    return 0; 
}