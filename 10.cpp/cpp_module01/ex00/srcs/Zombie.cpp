#include "../inc/Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::Zombie(std::string name)
{
    this->name = name; //name = newName(매개변수를 name)
};

Zombie::~Zombie()
{
    std::cout << "[DIED AGAIN 🧟‍♂️ | 🧟‍♀️ " << name  << ']' << ": Zombie is Disappear" << std::endl;
};