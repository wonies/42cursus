#include "push_swap.h"

long long   b_max(t_node **b)
{
    long long   max;
    t_node      *temp;

    max = -2147483649;
    temp = *b;
    while (temp)
    {
        if (max < temp->value)
            max = temp->value;
        temp = temp->next;
    }
    return (max);
}

int b_max_order(t_node **b, long long max)
{
    int     cnt;
    t_node  *temp;

    cnt = 0;
    temp = *b;
    while (temp)
    {
        cnt++;
        if (temp->value == max)
            break ;
        temp = temp->next;
    }
    return (cnt);
}