#include <iostream>

int &AddNum(int &arg)
{
    arg++;
    return arg; 
}


int main(void)
{
    int num1 = 1;
    int num2 = AddNum(num1);
    std::cout << &num1 << std::endl;
    std::cout << &num2 << std::endl;

    num1++;

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << &num1 << std::endl;
    std::cout << &num2 << std::endl;

    int &num3 = AddNum(num1);
    num1++;

    std::cout << num1 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << &num1 << std::endl;
    std::cout << &num3 << std::endl;
    
    num3 = 5;
    std::cout << num3 << std::endl; 
    return 0;
}