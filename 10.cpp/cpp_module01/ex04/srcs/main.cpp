#include "../inc/sed.hpp"

void sed(char **av)
{
    Sed data(av[1], av[2], av[3]);

    data.program();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "We need just 3 arguments" << std::endl;
        return (0);
    }
    sed(av);
}
