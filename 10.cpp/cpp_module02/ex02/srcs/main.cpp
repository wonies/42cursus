#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // Fixed c(20);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    //static const & non-const
    // Fixed &ref = Fixed::min( a, c );
    // std::cout << "non-const : " << ref.getValue() << std::endl;
    // ref.setValue( 20 );
    // std::cout << "setting non-const : " << ref.getValue() << std::endl;
    
    
    // Fixed const &con_ref = Fixed::min( a, c );
    // std::cout << "const : " << con_ref.getValue() << std::endl;
    // ref.setValue( 30 ); //error
    // std::cout << "setting const : " << con_ref.getValue() << std::endl; //error

    return 0;
}