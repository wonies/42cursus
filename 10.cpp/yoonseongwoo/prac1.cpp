#include <iostream>

int main(void)
{
    int input;
    int sum = 0;

    for(int i=0; i<5; i++)
    {
        std::cout<<i+1<<"번째 숫자입력 : ";
        std::cin>>input;
        sum += input;
    }
    std::cout<<"sum: "<<sum<<std::endl;


    return 0;
}