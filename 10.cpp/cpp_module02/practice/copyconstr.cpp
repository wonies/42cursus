#include <iostream>

class Simple
{
private:
    int num1;
    int num2;
public:
    Simple(int _num1, int _num2) : num1(_num1), num2(_num2){};
    Simple(Simple &copy) : num1(copy.num1), num2(copy.num2)
    {
        std::cout << "Called Simple (simple &copy)" << std::endl;
    }
    void ShowSimple()
    {
        std::cout << num1 << std::endl;
        std::cout << num2 << std::endl;
    }
};

int main( void )
{
    Simple sim1(15, 20);
    std::cout << "before create and initalize" << std::endl;
    Simple sim2= sim1;
    std::cout << "after cre ate and initalize" << std::endl;
    sim2.ShowSimple();
    return 0;
}