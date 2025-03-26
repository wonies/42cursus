#include "SpellBook.hpp"

SpellBook::SpellBook()
{
    return ;
}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator head = _spellList.begin();
    std::map<std::string, ASpell *>::iterator tail = _spellList.end();

    while (head!=tail)
    {
        delete(head->second);
        ++head;
    }
    _spellList.clear();
}

void SpellBook::learnSpell(ASpell *ptr)
{
    if (ptr)
        _spellList.insert(std::pair<std::string, ASpell*>(ptr->getName(), ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &spellname)
{
    std::map<std::string, ASpell*>::iterator it = _spellList.find(spellname);
    if (it!=_spellList.end())
        delete (it->second);
    _spellList.erase(spellname);
}

ASpell* SpellBook::createSpell(std::string const &spellname)
{
    std::map<std::string, ASpell*>::iterator it = _spellList.find(spellname);
    if (it != _spellList.end())
        return _spellList[spellname];
    return NULL;
}