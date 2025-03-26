#include <iostream>
#include <string>

int main(void)
{
	std::string brain;
	std::string *stringPTR;
	std::string &stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;

	std::cout << "[STRING ADDRESS] " << &brain << std::endl;
	std::cout << "[POINTER BY STRING 🌷PTR] " << stringPTR << std::endl;
	std::cout << "[POINTER BY STRING 🌹REF] " << &stringREF << std::endl;
	std::cout << "[THE VALUE OF STRING] " << brain << std::endl;
	std::cout << "[THE VALUE OF STRING 🌷PTR] " << *stringPTR << std::endl;
	std::cout << "[THE VALUE OF STRING 🌹REF] " << stringREF << std::endl;

	return 0;
}
