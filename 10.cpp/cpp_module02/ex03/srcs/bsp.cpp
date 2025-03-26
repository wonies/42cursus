#include "Point.hpp"

Point line( const Point &start, const Point &end )
{   
    Fixed deltaX = start.getX() - end.getX();
    Fixed deltaY = start.getY() - end.getY();
    
    //check line
    // std::cout << "start getX - end getX: \t"  << start.getX().toInt()- end.getX().toInt() << std::endl;
    // std::cout << "start getX - end getX: \t"  << start.getY().toInt()- end.getY().toInt() << std::endl;
    
    return (Point(deltaX, deltaY));
} 

int cross( const Point &leg, const Point &toPoint )
{
    Fixed res = leg.getX() * toPoint.getY();
    
    //check cross X & Y == Z index == (ax * by - ay * bx) 
    // std::cout << "leg value : \t" << leg.getX() / 256 << std::endl;
    // std::cout << "point value : \t" << toPoint.getX() / 256 << std::endl;
    res = ((leg.getX() / 256) * (toPoint.getY() / 256)) - ((leg.getY() / 256) * (toPoint.getX() / 256));
    
    return (res.getValue() / 256);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    int _a = cross(line( a, b ), line(a ,point));
    int _b = cross(line( b, c ), line(b, point));
    int _c = cross(line( c, a ), line(c, point));

    if ((_a >= 0 && _b >= 0 && _c >= 0 ) || \
        (_a < 0 && _b < 0 && _c < 0))
        return true;
    return false;

}