#include "push_swap.h"

void sa(t_node *a)
{
    int temp;
    
    if (a == NULL || a->next == NULL)
        return ;
    if (a->next != NULL && a->next->next != NULL)
    {
        temp = a->next->value;
        a->next->value = a->value;
        a->value = temp;
    }
}

void sb(t_node *b)
{
    int temp;

    if (b == NULL || b->next == NULL)
        return ;
    if (b->next != NULL && b->next->next != NULL)
    {
        temp = b->next->value;
        b->next->value = b->value;
        b->value = temp;
    }
}

void ss(t_node *a, t_node *b)
{
    sa(a);
    sb(b);
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
}

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
}

void    rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
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
}

void    rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
}