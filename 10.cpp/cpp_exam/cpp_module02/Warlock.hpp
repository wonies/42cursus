#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        SpellBook _spellBook;

        Warlock();
        Warlock(Warlock const &src);
        Warlock& operator=(Warlock const &src);
        // Warlock(const &src);
        // Warlock(operator=);

    public:
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;
        Warlock(std::string const& _name, std::string const& _title);
        ~Warlock();

        void learnSpell(ASpell *ptr);
        void forgetSpell(std::string spellname);
        void launchSpell(std::string spellname, ATarget const &ref);


};