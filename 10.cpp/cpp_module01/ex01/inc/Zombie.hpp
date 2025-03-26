#ifndef __ZOMBIEHORDE_H
#define __ZOMBIEHORDE_H

#include <iostream>
#include <string>

class   Zombie
{
private:
    std::string name;
    int id;
public:
    static const int HordeSize = 5;
    Zombie();
    ~Zombie();
    void announce(int idx);
    void settingName(std::string naming);
    void setId(int id);
    // std::string getName() const {
    //     return name;
    // }
};

Zombie* zombieHorde( int N, std::string name );

#endif