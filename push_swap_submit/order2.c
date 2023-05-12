#include "push_swap.h"

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
    head->next = *a;
    *a = head;
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
