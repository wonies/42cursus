#include <iostream>

class Rectangle {
	private:
		int width;
		int height;
	public:
		Rectangle(int width, int height);
		Rectangle(const Rectangle& src);
		Rectangle& operator=(const Rectangle& rhs);
		void print(const Rectangle obj);
        void prints(const Rectangle &obj);
};

Rectangle::Rectangle(int width, int height) {
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(const Rectangle& src) {
	std::cout << "Copy Constructor" << std::endl;
	*this = src;
}

Rectangle& Rectangle::operator=(const Rectangle& rhs) {
	if (this != &rhs) {
		std::cout << "Copy Assignment Operator" << std::endl;
		this->width = rhs.width;
		this->height = rhs.height;
	}
	return (*this);
}

void Rectangle::print(const Rectangle obj) {
	std::cout << "Width: " << obj.width << std::endl;
	std::cout << "Height: " << obj.height << std::endl;
}

void Rectangle::prints(const Rectangle &obj) {
	std::cout << "Width: " << obj.width << std::endl;
	std::cout << "Height: " << obj.height << std::endl;
}

int main() 
{
	Rectangle r1(10, 20);
	r1.print(r1);
    r1.prints(r1);
	return 0;
}