#include <iostream>

using namespace std;

class Numbox
{
private:
    int _num1, _num2;
public:
    Numbox(int num1, int num2) : _num1(num1), _num2(num2){};
    void ShowNum()
    {
        cout << "num1 : " << _num1 << ", num2 : " << _num2 << endl;
    }
    Numbox operator+(Numbox &ref)
    {
        return Numbox(_num1+ref._num1, _num2+ref._num2);
    }
};

int main( void )
{
    Numbox nb1(10, 20);
    Numbox nb2(5, 2);
    //Numbox res = nb1 + nb2;
    Numbox res = nb1.operator+(nb2);

    nb1.ShowNum();
    nb2.ShowNum();
    res.ShowNum();
}