#ifndef __HUMAN_A_H
#define __HUMAN_A_H

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;

public:
    HumanA(const std::string &soldier, Weapon &weapon_type);
    void    attack();
    
};

#endif