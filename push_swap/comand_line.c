#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        if (ac == 2 && strcmp(av[1], "--help"))
            out = stdout;
        else
            out = stderr;
    }

    fprintf(out, "+-------+\n");

    if (out == stderr)
    {
        fprintf(out, "\nerror: invalid arguments\n");
        return 1;
    }
    return 0;   
}