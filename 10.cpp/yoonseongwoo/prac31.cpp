#include <iostream>
#include <cstring>
using namespace std;


class Point
{
private: 
    int xpos, ypos;
public: 
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    int radi;
    Point center;
public:
    void Init(int x, int y, int r)
    {
        radi = r;
        center.Init(x, y);
    }
    void ShowCircleInfo() const
    {
        cout<<"radius : "<<radi<<endl;
        center.ShowPointInfo();
    }
};


class Ring
{
    Circle inner;
    Circle outer;
public:
    void Init(int o_x, int o_y, int o_r, int i_x, int i_y, int i_r)
    {
        inner.Init(i_x, i_y, i_r);
        outer.Init(o_x, o_y, o_r);
    }
    void ShowRingInfo()
    {
        cout<<"Inner Circle Info..."<<endl;
        inner.ShowCircleInfo();
        outer.ShowCircleInfo();
    }
};


int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}