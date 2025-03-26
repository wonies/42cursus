#include "../inc/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *horde = new Zombie[N];
    
    for (int i=0; i<N; i++)
	{
        horde[i].settingName(name);
		horde[i].setId(i);
	}
	// horde[0].settingName("wonie");
    return horde;
}
