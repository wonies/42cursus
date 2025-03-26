#include <iostream>

class Simple
{
private:
    int num1;
    int num2;
public:
    Simple(int _num1, int _num2) : num1(_num1), num2(_num2){};
    void ShowSimple()
    {
        std::cout << num1 << std::endl;
        std::cout << num2 << std::endl;
    }
};

int main( void )
{
    Simple simple(15, 20);
    Simple simple2(15, 20);
    simple2.ShowSimple();
    return 0;
}