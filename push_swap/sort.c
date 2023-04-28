#include "push_swap.h"

int    create_chunk(t_node **a, t_info *info)
{
    int size = ft_lstsize(*a);
    int chunk = 0;
    printf("size : %d\n", size);
    info->size = size;
    if (size <= 5)
        return -1;
    else if (size < 100)
        chunk = 15;
    else
        chunk= 30;
    info->chunk = chunk;
    return chunk;
}

void    get_rank(t_node **a, t_info *info)
{
    int rank;
    int chunk;
    int size;

    rank = 0;
    size = info->size;
    chunk = create_chunk(a, info);
    get_order(a, info);
    printf("the size is what %d\n", info->size);
    
}

void    push_start(t_node **a, t_info *info, int chunk, t_node **b)
{
    int i = 0;
    t_node *temp; 
    while (1)
    {
        temp = *a;
        if ((*a) == NULL)
            break ;
        if (temp->order < chunk + i)
        {
            printf("a order : %d\n", (temp)->order);
            pb(a, b);
            if ((*b)->order < i)
                rrb(b);
            i++;
        }
        else
            ra(a);
        temp = (temp)->next;
    }
}

void    b_order(t_node **a, t_node **b, t_info *info)
{
    long long max;
    t_node  *temp;
    int count;
    int i;
    t_node  *tmp;

    count = ft_lstsize(*b);
    while (count > 0)
    {
        max = -2147483649;
        temp = *b;
        while (temp)
        {
            if (max < temp->value)
                max = temp->value;
            temp = temp->next;
        }
        tmp = *b;
        while (tmp)
        {
            if (tmp->value == max)
            {
                pa(a, b);
                count--;
                break ;
            }
            else
                rb(b);
            tmp = tmp->next;
        }
    }
}

void    get_order(t_node **a, t_info *info)
{
    int rank;
    long long  min;
    
    t_node *temp;
    rank = 1;
    while (rank <= info->size)
    {
        min = 2147483648;
        temp = *a;
        while (temp)
        {
            if (min > temp->value && (temp->order == 0))
                min = temp->value;
            temp = temp->next;
        }
        t_node *tmp = *a;
        while (tmp)
        {
            if (tmp->value == min)
                tmp->order = rank++;
            tmp = tmp->next;
        }
    }
}
