#include "push_swap.h"

int    create_chunk(t_node **a, t_info *info)
{
    int size = ft_lstsize(*a);
    int chunk = 0;
    printf("size : %d\n", size);
    if (size <= 5)
        return -1;
    else if (size < 100)
        chunk = 15;
    else
        chunk= 30;
    info->size = size;
    info->chunk = chunk;

    return chunk;
}

void    get_rank(t_node **a, t_info *info)
{
    int rank;
    
    rank = 0;
    create_chunk(a, info);
    

}