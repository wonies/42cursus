#include "push_swap.h"

int    create_chunk(t_node **a, t_info *info)
{
    int size = ft_lstsize(*a);
    int chunk = 0;
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


void    three_algo(t_node **a)
{
    t_node *temp;
    t_node *temp_next;
    t_node *last;
    
    last = ft_lstlast(*a);
    temp = *a;
    printf("temp order : %d\n", temp->order);
    temp_next = temp->next;
    printf("temp next_order : %d\n", temp_next->order);
    printf("last order : %d\n", last->order);


    /* 1 3 2 */
    
    if (temp->order < temp_next->order && temp_next->order > last->order && temp->order < last->order)
    {
        sa(*a);
        ra(a);
    }
    /* 2 1 3 */
    else if (temp->order > temp_next->order && temp_next->order < last->order && temp->order < last->order)
        sa(*a);
    /* 2 3 1 */
    else if (temp->order < temp_next->order && temp_next->order > last->order && temp->order > last->order)
        rra(a);
    /* 3 1 2 */
    else if (temp->order > temp_next->order && temp_next->order < last->order && temp->order > last->order)
        ra(a);
    /* 3 2 1 */
    else if (temp->order > temp_next->order && temp_next->order > last->order && temp->order > last->order)
    {
        sa(*a);
        rra(a);
    }
}

void    five_algo(t_node **a, t_node **b)
{
    three_algo(a);
    pb(a, b);
    three_algo(a);
    pb(a, b);
    three_algo(a);
    if ((*b)->value < (*b)->next->value)
        sb(*b);
    pa(a, b);
    three_algo(a);
    pa(a, b);
    three_algo(a);
}


void count_each(t_node **a, t_info *info, t_node **b)
{
    int size;
    size = info->size;
    if(size <= 3)
        three_algo(a);
    else if (size <= 5)
       five_algo(a, b);
} 


void    get_rank(t_node **a, t_info *info, t_node **b)
{
    int rank;
    int chunk;
    int size;


    rank = 0;
    size = info->size;
    chunk = create_chunk(a, info);
    get_order(a, info);
    if (chunk == -1)
    {
        count_each(a, info, b);
        return ;
    }
    push_start(a, info, chunk, b);
    b_order(a, b, info);
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
    long long   max;
    int         cnt;
    int         count;

    count = ft_lstsize(*b);
    while (count > 0)
    {
        max = b_max(b);
        cnt = b_max_order(b, max);
        // tmp = *b; -> 왜 이렇게 해서 if문에 넣으면 안될까?
        while (1)
        {
            if ((*b)->value == max)
            {
                pa(a,b);
                count--;
                break ;
            }
            if (cnt < (info->size / 2))
                rb(b);
            else
                rrb(b);
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
