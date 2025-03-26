#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator head = _spellBook.begin();
    std::map<std::string, ASpell*>::iterator tail = _spellBook.end();

    while(head!=tail)
    {
        delete (head->second);
        ++head;
    }
    _spellBook.clear();
}

void SpellBook::learnSpell(ASpell *ptr)
{
    if (ptr)
        _spellBook.insert(std::pair<std::string, ASpell*>(ptr->getName(), ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &spellname)
{
    std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellname);
    if (it != _spellBook.end())
        delete it->second;
    _spellBook.erase(spellname);
}

ASpell *SpellBook::createSpell(std::string const &spellname)
{
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellname);
        printf("Debug\n");

    if (it != _spellBook.end())
    {
        printf("Debug\n");
       return  _spellBook[spellname];
    }
    return NULL;
    
}