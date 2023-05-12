#include "push_swap.h"


int optimize(t_node **a, t_info *info)
{
    int     front;
    int     center;
    int     tri;
    int     cnt;
    t_node *temp;

    front = 1;
    center = info->size / 2;
    tri = info->size / 3;
    temp = *a;
    cnt = 0;
    while (temp)
    {
        if (center <= front && temp->order <= tri)
            cnt++;
        temp = temp->next;
        front++;
    }
    if (cnt >= (tri / 4) * 3)
        return 1;
    else
        return -1;
}

int    create_chunk(t_node **a, t_info *info)
{
    int size = ft_lstsize(*a);
    int chunk = 0;
    info->size = size;
    if (size <= 5)
        return -1;
    else if (size <= 100)
        chunk = 15;
    else
        chunk= 30;
    info->chunk = chunk;
    return chunk;
}


void    three_algo(t_node **a)
{
//     t_node *temp;
//     t_node *temp_next;
//     t_node *last;
    
//     last = ft_lstlast(*a);
//     temp = *a;
//    // printf("temp order : %d\n", temp->order);
//     temp_next = (*a)->next;
//     // printf("temp next_order : %d\n", temp_next->order);
//     // printf("last order : %d\n", last->order);

//     /* 1 3 2*/
//     if (temp->order < temp_next->order && temp_next->order > last->order && temp->order < last->order)
//     {
//         sa(*a);
//         ra(a);
//     }
//     /*2 1 3*/
//     else if (temp->order > temp_next->order && temp_next->order < last->order && temp->order < last->order)
//         sa(*a);
//     /* 2 3 1*/
//     else if (temp->order < temp_next->order && temp_next->order > last->order && temp->order > last->order)
//         rra(a);
//     /* 3 1 2 */
//     else if (temp->order > temp_next->order && temp_next->order < last->order && temp->order > last->order)
//         ra(a);
//     /* 3 2 1*/
//     else if (temp->order > temp_next->order && temp_next->order > last->order && temp->order > last->order)
//     {
//         sa(*a);
//         rra(a);
//     }
    t_node	*temp;
	t_node	*last;

	temp = (*a)->next;
	last = ft_lstlast(*a);
	if ((*a)->order < last->order && last->order < temp->order)
	{
		sa(*a);
		ra(a);
	}
	else if (temp->order < (*a)->order && (*a)->order < last->order)
		sa(*a);
	else if ((*a)->order < temp->order && (*a)->order > last->order)
		rra(a);
	else if ((*a)->order > last->order && temp->order < last->order)
		ra(a);
	else if ((*a)->order > temp->order && temp->order > last->order)
	{
		sa(*a);
		rra(a);
	}
}

void    five_algo(t_node **a, t_node **b)
{
    t_node * temp;
    // temp = *a;
    // while (temp)
    // {
    //         printf(" a 의 vlaue 는??%d\n", temp->order);
    //         temp = temp->next;
    // }
    int	cnt;

	cnt = ft_lstsize(*a);
    
    three_algo(a);
    // temp = *a;
    // while (temp)
    // {
    //         printf(" a 의 order 는??%d\n", temp->value);
    //         temp = temp->next;
    // }
    pb(a, b);
    //  temp = *a;
    // while (temp)
    // {
    //         printf(" a 2 의 order 는??%d\n", temp->value);
    //         temp = temp->next;
    // }
    //   temp = *a;
    // while (temp)
    // {
    //         printf(" a 의 vlaue 는??%d\n", temp->order);
    //         temp = temp->next;
    // }
    // int cnt = ft_lstsize(*a);
    three_algo(a);
    //  temp = *a;
    // while (temp)
    // {
    //         printf(" a 3 의 order 는??%d\n", temp->value);
    //         temp = temp->next;
    // }
    pb(a, b);
    // t_node *pbs;
    // pbs = *b;
    // while (pbs)
    // {
    //     printf("show me the B: %d\n", pbs->value);
    //     pbs = pbs->next;
    // }
    three_algo(a);
    // temp = *a;
    // while (temp)
    // {
    //         printf(" a 4 의 order 는??%d\n", temp->value);
    //         temp = temp->next;
    // }
    if ((*b)->order < (*b)->next->order)
        sb(*b);
    //  pbs = *b;
    // while (pbs)
    // {
    //     printf("show me the B: %d\n", pbs->value);
    //     pbs = pbs->next;
    // }
    pa(a, b);
    // temp = *a;
    // while (temp)
    // {
    //         printf(" a 3 의 order 는??%d\n", temp->value);
    //         temp = temp->next;
    // }
    three_algo(a);
    pa(a, b);
    three_algo(a);
	// while (cnt-- > 0)
	// {
	// 	pa(a, b);
	// 	three_algo(a);
	// }
    // while (cnt-- > 0)
    // {
    //     pa(a, b);
    //     three_algo(a);
    // }
    // pa(a, b);
    // temp  =*a;
    //   while (temp)
    // {
    //         printf(" a 의 vlaue 는??%d\n", temp->order);
    //         temp = temp->next;
    // }
    // three_algo(a);
}


void count_each(t_node **a, t_info *info, t_node **b)
{
    int size;
    size = info->size;
    if (size == 2)
        sa(*a);
    else if(size <= 3)
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
    sort_b(a, b, info);
}

void    push_start(t_node **a, t_info *info, int chunk, t_node **b)
{
    int i = 0;
    t_node *temp;
    int size = info->size; 
    int opti;

    opti = optimize(a, info);
    // printf("size : %d\n", size);
    // while (i < size)
	// {
	// 	if ((*a)->order > chunk + i)
	// 		ra(a);
	// 	else
	// 	{
	// 		if ((*a)->order < i)
	// 			pb(a, b);
	// 		else
	// 			rrb(b);
    //         i++;
	// 	}
	// }
    
    while (i < size)
    {
        if ((*a)->order > chunk + i)
        {
            if (opti == 1)
                rra(a);
            else
                ra(a);
        }
        else
        {
            if ((*a)->order < i)
                pb(a, b);
            else 
            {
                pb(a, b);
                rb(b);
            }
            i++;
        }
    }

    // while (i < size)
    // {
    //     temp = *a;
    //     // if ((*a) == NULL)
    //     //     break ;
    //     if ((*a)->order < chunk + i)
    //     {
    //         // if ( i < chunk)
    //             pb(a, b);
    //         if ((*b)->order > i)
    //             rrb(b);
    //         // if ((*b)->order < i)
    //             // rrb(b);
    //         i++;
    //     }
    //     else
    //         ra(a);
    //     // temp = (temp)->next;
    // }

    //  while (1)
    // {
    //     temp = *a;
    //     if ((*a) == NULL)
    //         break ;
    //     if (temp->order < chunk + i)
    //     {
    //         pb(a, b);
    //         if ((*b)->order < i)
    //             rrb(b);
    //         i++;
    //     }
    //     else
    //         ra(a);
    //     temp = (temp)->next;
    // }
    // // while (1)
    // {
    //     temp = *a;
    //     if (temp == NULL)
    //         break ;
    //     if (temp->order > chunk + i)
    //         ra(a);
    //     else
    //     {
    //         if ( (temp->order <  i))
    //             pb(a, b);
    //         else 
    //             rrb(b);
    //         i++;
    //     }
    //     temp = (temp)->next;
    // }
}

int find_order(t_node **b, int size, int len)
{
    t_node *temp;
    int high;

    temp = *b;
    high = 1;
    while (temp->order != size)
    {
        high++;
        temp = temp->next;
    }
    if (high <= len)
        return 1;
    return 2;
}

void    b_order(t_node **a, t_node **b, int size)
{
    int len;
    int k;

    len = size / 2;
    if ((*b)->order == size)
        return ;
    k = find_order(b, size, len);
    while (1)
    {
        if (k == 1)
            rb(b);
        else if (k == 2)
            rrb(b);
        if ((*b)->order == size)
            break ;
    }
}

void sort_b(t_node **a, t_node **b, t_info *info)
{
    int f_order;

    f_order = info->size;
    while (f_order != 0)
    {
        b_order(a, b, f_order);
        pa(a, b);
        f_order--;
    }
}

// void    b_order(t_node **a, t_node **b, t_info *info)
// {
//     long long   max;
//     int         cnt;
//     int         count;

//     int size = info->size;
//     int len =  size / 2;
//     int flag = 0;
//     int  i= 0;
//     int con = b_max_order(b, max);
//     //count = ft_lstsize(*b);
//     max = b_max(b);
//     if ((*b)->order == con)
//         return ;
//     if (con <= len)
//         flag = 1;
//     else
//         flag = 2;
//     while (i < size)
//     {
//         while (1)
//         {
//             if ((*b)->order == con)
//                 break ;
//             if (flag == 1)
//                 rb(b);
//             else if (flag == 2)
//                 rrb(b);
//         }
//         pa(a, b);
//         i++;
//     }

//     // while (count > 0)
//     // {
//     //     max = b_max(b);
//     //     cnt = b_max_order(b, max);
//     //     // tmp = *b; -> 왜 이렇게 해서 if문에 넣으면 안될까?
//     //     while (1)
//     //     {
//     //         if ((*b)->order == max)
//     //         {
//     //             pa(a,b);
//     //             count--;
//     //             break ;
//     //         }
//     //         if (cnt < (info->size / 2))
//     //             rb(b);
//     //         else
//     //             rrb(b);
//     //     }
//     // }
// }

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
