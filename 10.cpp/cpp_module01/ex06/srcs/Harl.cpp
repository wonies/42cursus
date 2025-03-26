#include "../inc/Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

Harl::~Harl( void )
{

}

int Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int switchnum = 0;
	
	for (int i=0; i<4; i++)
	{
		if ( level.compare(levels[i]) == 0)
		{
			switchnum = i + 1;
            return (switchnum);
		}
        switchnum = 0;
	}
    return (switchnum);
}

void Harl::switchloop( std::string level )
{
    int switchnum = complain( level );

    switch (switchnum)
    {
    case 1:
        (this->*HarlsFunc[0])();
        __attribute__((fallthrough));
    case 2:
        (this->*HarlsFunc[1])();
        __attribute__((fallthrough));
    case 3:
        (this->*HarlsFunc[2])();
        __attribute__((fallthrough));
    case 4:
        (this->*HarlsFunc[3])();
        break ;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}


