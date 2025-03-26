#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &soldier)
{
    this->name = soldier;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon_type)
{
    weapon = &weapon_type;
}

void HumanB::attack(void)
{
    if (weapon)
        {
            if (weapon->isUsable())
            {
                std::cout << "Enemy team : " << this->name << " attacks with their⚔️ " << weapon->getType() << "\n\n" << std::endl;
                weapon->decreaseDura();
            }
            if (!weapon->isUsable())
            {
                std::cout << "\n\n🛎  " << name << "'s weapon has destroyed\nNEED SUPPLY . . . \n\n" << std::endl;
                weapon = NULL;
            }
        }
    else
        std::cout << "Enemy team : " << this->name << " cannot attack 🔱 " << "\n\n" << std::endl;
}
