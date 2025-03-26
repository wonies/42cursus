#ifndef __FIXED__H__
#define __FIXED__H__

#include <iostream>
#include <string>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed &operator= (const Fixed &obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

};


#endif