#include <iostream>

class Simple
{
private:
    int num;
public:
    Simple(int n) : num(n)
    {
        std::cout << "New object : " << this << std::endl;
    }
    Simple(const Simple &copy) : num(copy.num)
    {
        std::cout << "New copy : " << this << std::endl;
    }
    ~Simple()
    {
        std::cout << "Destroy obj: " << this << std::endl;
    }
};

Simple SimFun(Simple obj)
{
    std::cout << "Parameter : " << &obj << std::endl;
    return obj;
}

int main( void )
{
    Simple obj(7);
    SimFun(obj);

    std::cout << std::endl;
    Simple tempRef = SimFun(obj);
    std::cout << "Return Obj " << &tempRef << std::endl;


    return 0;
}