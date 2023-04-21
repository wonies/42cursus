#include "push_swap.h"

// int ft_atoll(const char *str)
// {
//     long long   result;
//     int         n;

//     result = 0;
//     n = 1;

// }

int print_error(int err)
{
    if (err == -42)
        write(2, "Error\n", 6);
    exit(1);
    return (-1);
}