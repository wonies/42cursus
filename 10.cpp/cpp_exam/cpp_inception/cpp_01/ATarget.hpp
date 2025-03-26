#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{

    private:
        std::string _type;
    public:
        ATarget(std::string const &type);
        ATarget();
        ATarget(ATarget const &src);
        ATarget& operator=(ATarget const &src);
        virtual ~ATarget();
        std::string const &getType() const;
        //METHODS
        void getHitBySpell(ASpell const &ref) const;
        virtual ATarget *clone() const = 0;
        

};