#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"


int main(void)
{
    {
        Weapon method = Weapon("dragon's staff");
        Weapon hallows = Weapon("Elder Wand staff");
        
        HumanA harry("potter", method);
        harry.attack();
        harry.attack();
        HumanB tom("riddle");
        tom.setWeapon(hallows);
        tom.attack();
        tom.attack();
        hallows.setType("new hallows");
        harry.attack();
        tom.setWeapon(hallows);
        tom.attack();
        tom.attack();
        tom.attack();
        tom.attack();
    }
   
    // {
    //     Weapon club = Weapon("crude spiked club");

    //     HumanA bob("Bob", club);
    //     bob.attack();
    //     club.setType("some other type of club");
    //     bob.attack();
    // }
    // {
    //     Weapon club = Weapon("crude spiked club");
        
    //     HumanB jim("Jim");
    //     jim.setWeapon(club);
    //     jim.attack();
    //     club.setType("some other type of club");
    //     jim.attack();
    //     jim.attack();
    // }

    return 0;
}
