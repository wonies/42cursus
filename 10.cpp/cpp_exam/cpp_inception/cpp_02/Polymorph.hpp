#pragma once

#include "ASpell.hpp"

class Polymorph: public ASpell
{
    public:

        // DEFAULT CONSTRUCTOR
        Polymorph();

        // DESTRUCTOR
        ~Polymorph();

        // METHOD
        virtual ASpell* clone() const;
};                                           