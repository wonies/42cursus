#ifndef __FIXED__H__
#define __FIXED__H__

#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed( const int val );
	Fixed( const float val );
	~Fixed( void );
	Fixed(const Fixed &ob);
	Fixed& operator= (const Fixed &obj);
	float toFloat( void ) const;
	int	toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	// float experiment( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif