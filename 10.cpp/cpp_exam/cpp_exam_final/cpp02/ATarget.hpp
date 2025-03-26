#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{

    private:
        std::string _type;
    public:
        ATarget();
        ATarget(ATarget const &src);
        ATarget& operator=(ATarget const &src);
        virtual ~ATarget();
        ATarget(std::string const &type);
        std::string const &getType() const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &) const;

};