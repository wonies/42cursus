#include "push_swap.h"

int print_error(int err)
{
    if (err == -42)
        write(2, "Error\n", 6);
    exit(1);
    return (-1);
}
