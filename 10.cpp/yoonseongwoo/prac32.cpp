#include <iostream>
#include <cstring>
using namespace std;


class Cons
{
private: 
    int num;
    int num2;
public: 
    Cons()
    {
        num = 0;
        num2 = 0;
    }
    Cons(int n)
    {
        num = n;
        num2 = 0;
    }
    Cons(int n1, int n2)
    {
        num = n1;
        num2 = n2;
    }
    // Cons(int n1 = 0, int n2 = 0)
    // {
    //     num = n1;
    //     num2 = n2;
    // }

    void ShowData() const{
        cout<<num<<' '<<num2<<endl;
    }
};

int main(void)
{
    Cons con;
    con.ShowData();

    Cons con2(100);
    con2.ShowData();
    
    Cons con3(100, 200);
    con3.ShowData();
    return 0;
}