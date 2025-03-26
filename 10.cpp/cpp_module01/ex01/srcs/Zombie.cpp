#include "../inc/Zombie.hpp"

void    Zombie::announce(int idx)
{
    std::cout << idx << ":\t" << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::Zombie()
{
};

Zombie::~Zombie()
{
    std::cout << "[DIED AGAIN 🧟‍♂️ | 🧟‍♀️ " << name  << ']' << ": " << id << "th Zombie is Disappear" << std::endl;
};

void    Zombie::settingName(std::string naming)
{
    name = naming;
}

void    Zombie::setId(int id)
{
    this->id = id;
}