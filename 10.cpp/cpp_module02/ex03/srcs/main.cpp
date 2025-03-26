#include "Point.hpp"

int main( void )
{
    Point const a(5, 5);
    Point const b(2, 9);
    Point const c(0, 5);
    Point const point(3, 7);
    Point const p2(4, 7);

    if (bsp(a, b, c, point ))
        std::cout << "The Point exist in Rectangle" << std::endl;
    else
        std::cout << "The Point is Out of range" << std::endl;
    if (bsp(a, b, c, p2 ))
        std::cout << "The Point exist in Rectangle" << std::endl;
    else
        std::cout << "The Point is Out of range" << std::endl;

    // Point test;
    // Point copy(1, 2);

    // test = copy;
    // std::cout << test.getX() << " " << test.getY() << "\n";

    return 0;
}