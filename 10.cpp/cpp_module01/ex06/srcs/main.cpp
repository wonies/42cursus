#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
    {
        std::cout << "🧾ENTER 2 ARGUMENTS🍿" << std::endl;
        return (0);
    }
    harl.switchloop(av[1]);
}
