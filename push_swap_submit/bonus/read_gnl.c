#include "push_swap_bonus.h"

int    check_command(char *line, t_node **a, t_node **b)
{
    if (ft_strncmp(line, "sa\n", 3) == 0)
        sa(*a, 0);
    else if (ft_strncmp(line, "sb\n", 3) == 0)
        sb(*b, 0);
    else if (ft_strncmp(line, "ss\n", 3) == 0)
        ss(*a, *b, 0);
    else if (ft_strncmp(line, "pa\n", 3) == 0)
        pa(a, b, 0);
    else if (ft_strncmp(line, "pb\n", 3) == 0)
        pb(a, b, 0);
    else if (ft_strncmp(line, "ra\n", 3) == 0)
        ra(a, 0);
    else if (ft_strncmp(line, "rb\n", 3) == 0)
        rb(b, 0);
    else if (ft_strncmp(line, "rr\n", 3) == 0)
        rr(a, b, 0);
    else if (ft_strncmp(line, "rra\n", 4) == 0)
        rra(a, 0);
    else if (ft_strncmp(line, "rrb\n", 4) == 0)
        rrb(b, 0);
    else if (ft_strncmp(line, "rrr\n", 4) == 0)
        rrr(a, b, 0);
    else
        return (-114);
    return (1);
}

void    process_commads(t_node **a, t_node **b, int size)
{
    char    *line;
    int     check;
    int     ord;

    check = 0;
    ord = 0;
    while (size)
    {
        line = get_next_line(0);
        if (line == NULL)
            break ;
        check = check_command(line, a, b);
        if (check == -114)
            print_error(-42);
    }
    if (check_sort(*a) == 1 && ft_lstsize(*b) == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}


// int order_command(t_node **a)
// {
//     if (check_sort(*a) == 1)
//         return (114);
//     else
//         return (-1);
// }