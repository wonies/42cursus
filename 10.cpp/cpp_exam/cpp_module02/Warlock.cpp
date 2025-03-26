#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";


}

std::string const &Warlock::getName() const{
    return _name;
}

std::string const &Warlock::getTitle() const
{
    return _title;
}

void Warlock::setTitle(const std::string &title) {
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *ptr)
{
    _spellBook.learnSpell(ptr);
}

void Warlock::forgetSpell(std::string spellname)
{
    _spellBook.forgetSpell(spellname);
}

void Warlock::launchSpell(std::string  spellname, ATarget const &ref)
{
    ATarget const *test = 0;
    if (test == &ref)
        return ;
    ASpell *spell = _spellBook.createSpell(spellname);
    if (spell)
        spell->launch(ref);
}


