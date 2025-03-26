#pragma once

#include "ASpell.hpp"

class Fireball: public ASpell
{
    public:

        // DEFAULT CONSTRUCTOR
        Fireball();

        // DESTRUCTOR
        ~Fireball();

        // METHOD
        virtual ASpell* clone() const;
};