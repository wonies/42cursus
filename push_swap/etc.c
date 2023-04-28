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

int check_duplication(t_node *a)
{
    t_node *cur;
    cur = a;
    while (cur)
    {
        t_node *tmp = cur->next;
        while (tmp)
        {
            if (cur->value == tmp->value)
                return -42;
            tmp = tmp->next;
        }
        cur = cur->next;
    }
    return 0;
}
