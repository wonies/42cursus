#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
    return ;
}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator head = _targetList.begin();
    std::map<std::string, ATarget *>::iterator tail = _targetList.end();

    while (head!=tail)
    {
        delete(head->second);
        ++head;
    }
    _targetList.clear();
}

void TargetGenerator::learnTargetType(ATarget *ptr)
{
    if (ptr)
        _targetList.insert(std::pair<std::string, ATarget*>(ptr->getType(), ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &spellname)
{
    std::map<std::string, ATarget*>::iterator it = _targetList.find(spellname);
    if (it!=_targetList.end())
        delete (it->second);
    _targetList.erase(spellname);
}

ATarget* TargetGenerator::createTarget(std::string const &spellname)
{
    std::map<std::string, ATarget*>::iterator it = _targetList.find(spellname);
    if (it != _targetList.end())
        return _targetList[spellname];
    return NULL;
}