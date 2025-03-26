#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
    // std::map<std::string, ATarget *>::iterator head = _TargetGenerator.begin();
    // std::map<std::string, ATarget*>::iterator tail = _TargetGenerator.end();

    // while(head!=tail)
    // {
    //     delete (head->second);
    //     ++head;
    // }
    // _TargetGenerator.clear();
}

void TargetGenerator::learnTargetType(ATarget *ptr)
{
    if (ptr)
        _TargetGenerator.insert(std::pair<std::string, ATarget*>(ptr->getType(), ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &Targetname)
{
    std::map<std::string, ATarget *>::iterator it = _TargetGenerator.find(Targetname);
    if (it != _TargetGenerator.end())
        delete it->second;
    _TargetGenerator.erase(Targetname);
}

ATarget *TargetGenerator::createTarget(std::string const &Targetname)
{
    std::map<std::string, ATarget*>::iterator it = _TargetGenerator.find(Targetname);
    if (it != _TargetGenerator.end())
       return  _TargetGenerator[Targetname];
    return NULL;
}