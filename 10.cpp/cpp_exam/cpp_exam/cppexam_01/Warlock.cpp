#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";

    std::map<std::string, ASpell *>::iterator head = _spellList.begin();
    std::map<std::string, ASpell*>::iterator tail = _spellList.end();
    while (head!=tail)
    {
        delete head->second;
        ++head;
    }
    _spellList.clear();
}

std::string const &Warlock::getName() const
{
    return _name;
}

std::string const &Warlock::getTitle() const
{
    return _title;
}

void Warlock::setTitle(std::string const &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *ref)
{
    if (ref)
        _spellList.insert(std::pair<std::string, ASpell*>(ref->getName(), ref->clone()));
}

void Warlock::forgetSpell(std::string spellname)
{
    std::map<std::string, ASpell *>::iterator it = _spellList.find(spellname);
    if (it != _spellList.end())
        delete (it->second);
    _spellList.erase(spellname);
}

void Warlock::launchSpell(std::string spellname, ATarget const &ref)
{
    ASpell *spell = _spellList[spellname];
    if (spell)
        spell->launch(ref);
}