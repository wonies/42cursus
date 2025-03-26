#pragma once

#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*> _spellList;
        SpellBook(SpellBook const &src);
        SpellBook& operator=(SpellBook const &src);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *ptr);
        void forgetSpell(std::string const &spellname);
        ASpell *createSpell(std::string  const &spellname);
};