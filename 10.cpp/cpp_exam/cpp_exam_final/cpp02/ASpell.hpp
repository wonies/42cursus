#pragma once

#include <iostream>
#include "ATarget.hpp"

class ASpell
{
    private:
        std::string _name;
        std::string _effects;
    public:
        ASpell();
        ASpell(ASpell const &src);
        ASpell& operator=(ASpell const &src);
        virtual ~ASpell();
        ASpell(std::string const &name, std::string const &effects);
        std::string const &getName() const;
        std::string const &getEffects() const;
        
        virtual ASpell* clone() const = 0;
        void launch(ATarget const &src) const;

};