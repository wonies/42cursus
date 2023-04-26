#include "push_swap.h"
#include <stdio.h>

void print_list(t_node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        print_error(-42);

    while (--ac > 0)
    {
        add_node(&stack_a, atoi(av[ac]));
    }
    sa(stack_a);
    print_list(stack_a);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    print_list(stack_a);
    print_list(stack_b);
    ra(&stack_a);
    rb(&stack_b);
    print_list(stack_a);
    print_list(stack_b);
    rr(&stack_a, &stack_b);
    print_list(stack_a);
    print_list(stack_b);
    printf("the rra result : ");
    rra(&stack_a);
    print_list(stack_a);
    rrr(&stack_a, &stack_b);
    print_list(stack_a);
    print_list(stack_b);   

    return (0);
}
