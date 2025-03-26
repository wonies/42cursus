#ifndef __HUMAN_B_H
#define __HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(const std::string &soldier);
    void    setWeapon(Weapon &weapon_type);
    void    attack(void);

};

#endif