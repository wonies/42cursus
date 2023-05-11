#include "push_swap.h"

void sa(t_node *a)
{
    int temp;
    int temp_order;
    
    if (a == NULL || a->next == NULL)
        return ;
    if (a != NULL && a->next != NULL)
    {
        temp = a->next->value;
        a->next->value = a->value;
        a->value = temp;
        temp_order = a->next->order;
        a->next->order = a->order;
        a->order = temp_order;
    }
    write(1, "sa\n", 3);
}

void sb(t_node *b)
{
    int temp;
    int temp_order;

    if (b == NULL || b->next == NULL)
        return ;
    if (b!= NULL && b->next != NULL)
    {
        temp = b->next->value;
        b->next->value = b->value;
        b->value = temp;
        temp_order = b->next->order;
        b->next->order = b->order;
        b->order = temp_order;
    }
    write(1, "sb\n", 3);
}

void ss(t_node *a, t_node *b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void    pa(t_node **a, t_node **b)
{
    t_node *temp;
    
    if (*b == NULL)
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

void    pb(t_node **a, t_node **b)
{
    t_node *temp;

    if (*a == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}

// void	ra(t_node **head)
// {
// 	t_node  *tmp;
// 	int		size;

// 	size = ft_lstsize(*head);
// 	tmp = *head;
// 	if (!tmp || size <= 1)
// 		return ;
// 	*head = (*head)->next;
// 	tmp->next = NULL;
// 	ft_lstadd_back(head, tmp);
//     write(1, "ra\n", 3);
// }


// void    ra(t_node **head)
// {
//     t_node *temp;
//     int size;

//     size = ft_lstsize(*head);
//     temp = *head;
//     if (!temp || size <= 1)
//         return ;
//     *head = (*head)->next;
//     temp->next = NULL;
//     ft_lstadd_back(head, size);
//     write(1, "ra\n", 3);
// }

void    ra(t_node **head)
{
    t_node *tail = *head;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = *head;
    *head = (*head)->next;
    tail->next->next = NULL;
    write(1, "ra\n", 3);
}

void    rb(t_node **head)
{
    t_node *tail = *head;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = *head;
    *head = (*head)->next;
    tail->next->next = NULL;
    write(1, "rb\n", 3);
}

void    rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void    rra(t_node **a)
{
    t_node *temp;
    t_node *head;

    head = *a;
    if (*a == NULL || (*a)->next == NULL)
        return ;
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
    }
    temp->next = NULL;
   // printf("head is ..%d\n",  head->value);
    head->next = *a;
    *a = head;
    // printf("a is ..%d\n", **a);
    write(1, "rra\n", 4);
}

void    rrb(t_node **b)
{
    t_node *temp;
    t_node *head;

    head = *b;
    if (*b == NULL || (*b)->next == NULL)
        return ;
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
    }
    temp->next = NULL;
    // printf("head is ..%d\n",  head->value);
    head->next = *b;
    *b = head;
    // printf("a is ..%d\n", **b);
    write(1, "rrb\n", 4);
}

void    rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}