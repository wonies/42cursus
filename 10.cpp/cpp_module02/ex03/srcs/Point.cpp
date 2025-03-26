#include "Point.hpp"

Point::Point( void ) : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point( const Point &pt ): x(pt.getX()), y(pt.getY())
{
}

Point& Point::operator= ( const Point &pt )
{
    const_cast<Fixed&>(this->x) = pt.getX();
    const_cast<Fixed&>(this->y) = pt.getY();
    (void)&pt;
    return (*this);
}

Point::~Point()
{
}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {
}

const Fixed& Point::getX( void ) const
{
    return (x);
}

const Fixed& Point::getY( void ) const
{
    return (y);
}
