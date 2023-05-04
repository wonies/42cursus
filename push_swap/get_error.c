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
    t_node  *cur;
    t_node  *tmp;
    
    cur = a;
    while (cur)
    {
        tmp = cur->next;
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

int check_sort(t_node *a)
{
    t_node  *tmp;
    t_node  *rear;
    int flag;
    int compare;
    int len;

    flag = 0;
    tmp = a;
    len = ft_lstsize(a);
    compare = a->value;
    while (tmp->next)
    {
        rear = tmp->next;
        if (compare < rear->value)
        {
            flag++;
            compare = rear->value;
        }
        tmp = tmp->next;
    }
    if (flag == len - 1)
        return -114;
    return 0;
}
