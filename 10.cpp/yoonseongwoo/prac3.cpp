#include <iostream>

int main(void)
{
    int gugu;
    int output = 0;
    
    std::cout<<"Enter the digit: ";
    std::cin>>gugu;

    for (int i=1; i<10; i++)
    {
        output = (gugu * i);
        std::cout<<gugu<< " * " << i << " = " << output <<std::endl;
    }
    return 0;
}
