#include <iostream>

using namespace std;

typedef struct Point
{
    int xpos;
    int ypos;
} Point;

Point &pointadd(const Point &p1, const Point &p2)
{
    Point *ptr = new Point;
    ptr->xpos = p1.xpos + p2.xpos;
    ptr->ypos = p1.ypos + p2.ypos; 
    return *ptr;
}

int main(void)
{
    Point *pptr = new Point;

    pptr->xpos = 20;
    pptr->ypos = 50;
    
    Point *pptr2 = new Point;

    pptr2->xpos = 25;
    pptr2->ypos = 99;

    Point &addpptr = pointadd(*pptr, *pptr2);
    cout<<"x pos: "<< addpptr.xpos <<endl;
    cout<<"y pos: "<< addpptr.ypos <<endl;
    delete pptr;
    delete pptr2;
    delete &addpptr;
    return 0;

}