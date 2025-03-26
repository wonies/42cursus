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
    return;
}

std::string const &ATarget::getType() const{
    return _type;
}


ATarget::ATarget(std::string const &type)
: _type(type)
{
    return ;
}

void ATarget::getHitBySpell(ASpell const &src) const
{
    std::cout   << _type
                << " has been "
                << src.getEffects()
                << "!\n";
}