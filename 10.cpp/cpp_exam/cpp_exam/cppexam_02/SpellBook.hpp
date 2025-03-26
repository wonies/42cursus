#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*> _spellBook;
        SpellBook(SpellBook const &src);
        SpellBook& operator=(SpellBook const &src);
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};