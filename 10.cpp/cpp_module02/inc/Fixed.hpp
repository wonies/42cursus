#ifndef __FIXED__H__
#define __FIXED__H__

#include <iostream>
#include <string>

class Fixed
{
private:
	int fixedInt;
	static const int bits = 8;
public:
	Fixed()
	{
		this->fixedInt = 0;
		std::cout << "Default constructor called" << std::endl;
	};
	Fixed(const Fixed& obj)
	{
		this->fixedInt = obj.fixedInt;
		std::cout << "Copy constructor called" << std::endl;
	};
	Fixed &operator= (const Fixed &obj)
	{
		this->fixedInt = obj.fixedInt;
		std::cout << "Copy assignment operator called"
		return *this;
	};
	~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	};
	int getRawBits( void ) const
	{
		std::cout << "getRawBits member function called" << std::endl;
		return this->fixedInt;
	};
	void setRawBits( int const raw )
	{
		this->fixedInt = raw;
		std::cout << this->fixedInt << std::endl;
	};
};

#endif