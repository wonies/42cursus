#include "ATarget.hpp"

ATarget::ATarget()
{
    return ;
}

ATarget::ATarget(ATarget const &src)
{
    *this = src;
}

ATarget &ATarget::operator=(ATarget const &src)
{
    _type = src._type;
    return *this;
}

ATarget::~ATarget()
{
}

std::string const &ATarget::getType() const{
    return _type;
}



ATarget::ATarget(std::string const &type)
: _type(type)
{
    return ;
}


void ATarget::getHitBySpell(ASpell const &ref) const{
    std::cout << _type << " has been " << ref.getEffects() << "!\n";
}