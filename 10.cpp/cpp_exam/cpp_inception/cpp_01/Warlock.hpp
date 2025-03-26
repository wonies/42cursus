#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>


class ASpell;
class ATarget;

class Warlock{

    private:
        Warlock();
        Warlock(Warlock const &src);
        Warlock& operator=(Warlock const &src);
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell *> _spellList;

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title) ;
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellname);
        void launchSpell(std::string spellname, ATarget const &ref); //const 빼먹음
};