#include "Polymorph.hpp"

// DEFAULT CONSTRUCTOR
Polymorph::Polymorph()
    : ASpell("Polymorph", "turned into a critter")
{
    return ;
}

// DESTRUCTOR
Polymorph::~Polymorph()
{
    return ;
}

// METHOD
ASpell* Polymorph::clone() const
{
    return (new Polymorph());
}