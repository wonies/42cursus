#include <iostream>

class Test
{
private:
	int wonie;
public:
	Test()
	{
		this->wonie = 0;
		std::cout << "call the DEFAULT constructor" << std::endl;
	};
	Test(const Test &obj)
	{
		this->wonie = obj.wonie;
		std::cout << "call the COPY constructor" << std::endl;
	};
	Test& operator=(const Test &obj)
	{
		this->wonie = obj.wonie;
		std::cout << "call the ASSIGNMENT constructor" << std::endl;
		return *this;
	};
	~Test()
	{
		std::cout << "call the DESTRUCTOR" << std::endl;
	};
	int getMember()
	{
		return this->wonie;
	}
};


bool isEmpty(Test t)
{
	if (t.getMember() == 0)
		return true;
	return false;
}

int main()
{
	Test t1; //default
	Test t2(t1); // copy
	Test t3 = t1; // copy
	t1 = t2; // assign

	std::cout << isEmpty(t1) << std::endl; //copy
	return 0;
}