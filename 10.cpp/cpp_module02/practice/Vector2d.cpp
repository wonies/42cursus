#include <iostream>

// Practice operate overloading

class Vector2D
{
public:
    Vector2D(float x, float y) : x(x), y(y){}
    float getX() const { return x; }
    float getY() const { return y; }
    Vector2D operator+(const Vector2D &other) const
    {
        return Vector2D(x + other.x, y + other.y);
    }
    bool operator==(const Vector2D &other) const
    {
        return x == other.x && y == other.y;
    }
private:
    float x, y;
};

int main( void )
{
    Vector2D vector1(1.0, 2.0);
    Vector2D vector2(3.0, 4.0);

    Vector2D sum = vector1 + vector2;
    bool areEqual = vector1 == vector2;
    
    std::cout << "Sum : (" << sum.getX() << ", " << sum.getY() << ")" << std::endl;
    std::cout << "Vector and Vector2 are equal: " << areEqual  << std::endl;

    return (0);
}