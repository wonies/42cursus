#ifndef __POINT__H__
#define __POINT__H__

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point( void );
    ~Point( void );
    Point( const Point &pt );
    Point& operator= ( const Point &pt );
    Point(const Fixed &s, const Fixed &e);
    const Fixed &getX() const ;
    const Fixed &getY() const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif