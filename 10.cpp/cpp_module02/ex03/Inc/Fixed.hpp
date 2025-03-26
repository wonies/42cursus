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
	Fixed operator+( const Fixed &val ) const;
	Fixed operator-( const Fixed &val ) const;
	Fixed operator*( const Fixed &val ) const;
	Fixed operator/( const Fixed &val ) const;
	bool operator>(const Fixed &val ) const;
	bool operator<(const Fixed &val ) const;
	bool operator>=(const Fixed &val ) const;
	bool operator<=(const Fixed &val ) const;
	bool operator==(const Fixed &val ) const;
	bool operator!=(const Fixed &val ) const;
	Fixed& operator--( void );
	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed operator--( int );
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	int getValue( void ) const;
	void setValue( int newval ); // const vs non-const
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif