#pragma once
#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell{

    private:
        std::string _name;
        std::string _effects;
    public:
        ASpell(std::string const &name, std::string  const &effects);
        ASpell();
        ASpell(ASpell const &src);
        ASpell& operator=(ASpell const &src);
        virtual ~ASpell();
        std::string const &getName() const;
        std::string const &getEffects() const;
        
        //METHODS
        void launch(ATarget const &ref) const;
        virtual ASpell *clone() const = 0;
};