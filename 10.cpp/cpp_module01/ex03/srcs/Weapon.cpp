#include "../inc/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string initial_weapon)
{
    this->type = initial_weapon;
    this->duration = 4;
};

const std::string& Weapon::getType(void) 
{
    return (this->type);
}

void Weapon::setType( std::string text)
{
    this->type = text;
    this->duration = 4;
}

void Weapon::decreaseDura(void)
{
    if (this->duration > 0)
        this->duration--;
}

bool Weapon::isUsable(void) const
{
    return (this->duration > 0);
}

void Weapon::resetDura(void)
{
    this->duration = 4;
}
