#ifndef __WEAPON_H
#define __WEAPON_H

#include <iostream>
#include <string>

// #include "HumanA.hpp"
// #include "HumanB.hpp"

class Weapon
{
private:
    std::string type;
    int duration;
    bool destroy;

public:
    Weapon();
    Weapon(std::string initial_weapon);
    ~Weapon();
    const std::string& getType();
    void setType( std::string text);
    void decreaseDura();
    bool isUsable() const;
    void resetDura();

};


#endif