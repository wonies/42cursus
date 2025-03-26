#include "Fireball.hpp"


Fireball::Fireball()
    : ASpell("Fireball", "burnt to a crisp")
{
    return ;
}

// DESTRUCTOR
Fireball::~Fireball()
{
    return ;
}

// METHOD
ASpell* Fireball::clone() const
{
    return (new Fireball());
}