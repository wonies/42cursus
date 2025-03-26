#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
};

Fixed& Fixed::operator= (const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->value = obj.getRawBits();
    }
    return *this;
};

Fixed::Fixed(const int val) : value(val << Fixed::bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : value(roundf((float)(val * (1 << Fixed::bits))))
{
    std::cout << "Float constructor called" << std::endl;
}


float Fixed::toFloat( void ) const
{
    //(float)(this->value / (1 << Fixed::bits) comparasion!
    return ((float)this->value / 256);
}

int Fixed::toInt( void ) const
{
    return (this->value >> Fixed::bits);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
};

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	 os << obj.toFloat();
    return os;
};

// float Fixed::experiment( void ) const
// { 
//     return this->value;
// }