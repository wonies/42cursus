#include <iostream>

int main(void)
{
    char name[100];
    char phone[200];

    std::cout<<"Name : ";
    std::cin>>name;

    std::cout<<"Phone Number: ";
    std::cin>>phone;

    std::cout<<name<< " && " <<phone<<std::endl;

    return 0;
}