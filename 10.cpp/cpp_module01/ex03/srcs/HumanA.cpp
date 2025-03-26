#include "../inc/HumanA.hpp"

HumanA::HumanA(const std::string &soldier, Weapon &weapon_type)
: weapon(weapon_type)
{
    this->name = soldier;
}

 void HumanA::attack()
{
    std::cout << "Ally team : " << this->name << " attacks with their⚔️ " << weapon.getType() << "\n\n" << std::endl;
}
