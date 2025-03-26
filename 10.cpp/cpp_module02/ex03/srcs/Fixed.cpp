#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
{
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed(const Fixed& obj)
{
    *this = obj;
};

Fixed& Fixed::operator= (const Fixed &obj)
{
    if (this != &obj)
    {
        this->value = obj.getRawBits();
    }
    return *this;
};

Fixed::Fixed(const int val) : value(val << Fixed::bits)
{
}

Fixed::Fixed(const float val) : value(roundf((float)(val * (1 << Fixed::bits))))
{
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
    return (this->value);
};

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
};

Fixed Fixed::operator+( const Fixed &val) const
{
    return Fixed(this->value + val.value);
}

Fixed Fixed::operator-( const Fixed &val) const
{
    return Fixed(this->value - val.value);
}

Fixed Fixed::operator*( const Fixed &val) const
{
    return Fixed(float((this->value * val.value) / 256) / 256);
}

Fixed Fixed::operator/( const Fixed &val) const
{
    return Fixed(this->value / val.value);
}

bool Fixed::operator>( const Fixed &val ) const
{
    return (this->value > val.value);
}

bool Fixed::operator<( const Fixed & val ) const
{
    return (this->value < val.value);
}

bool Fixed::operator>=( const Fixed & val ) const
{
    return (this->value >= val.value);
}

bool Fixed::operator<=( const Fixed & val ) const
{
    return (this->value <= val.value);
}

bool Fixed::operator==( const Fixed & val ) const
{
    return (this->value == val.value);
}

bool Fixed::operator!=( const Fixed & val ) const
{
    return (this->value != val.value);
}

Fixed& Fixed::operator++( void )
{
    value++;
    return (*this);
}

Fixed& Fixed::operator--( void )
{
    value--;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
    this->value--;
    return temp;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getValue() < b.getValue()) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getValue() > b.getValue()) ? a : b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
   return (a.getValue() < b.getValue()) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getValue() > b.getValue()) ? a : b;
}

int Fixed::getValue( void ) const
{
    return value;
}

void Fixed::setValue( int newval ) 
{
    value = newval;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	 os << obj.toFloat();
    return os;
};
