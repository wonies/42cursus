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
    t_info  a_len;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        print_error(-42);

    while (--ac > 0)
    {
        add_node(&stack_a, ft_atoi(av[ac]));
        if (ft_atoi(av[ac]) == 110401080911)
            print_error(-42);
    }
    t_node *temp;
    temp = stack_a;
    while (temp)
    {
        if (check_duplication(stack_a) == -42)
            print_error(-42);
        temp = temp->next;
    }
    // sa(stack_a);
    // print_list(stack_a);
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // print_list(stack_a);
    // print_list(stack_b);
    // ra(&stack_a);
    // ra(&stack_a);
    // ra(&stack_a);
    // pb(&stack_a, &stack_b);
    // rb(&stack_b);
    // print_list(stack_a);
   // print_list(stack_b);
    // rr(&stack_a, &stack_b);
    // print_list(stack_a);
    // print_list(stack_b);
    // printf("the rra result : ");
    // rra(&stack_a);
    // print_list(stack_a);
    // rrr(&stack_a, &stack_b);
    //print_list(stack_a);

    get_rank(&stack_a, &a_len);
    push_start(&stack_a,&a_len,15,&stack_b);
    printf("B is ");
    print_list(stack_b);
    // while (stack_b)
    // {
    //     printf("value : {%d} order : {%d}\n", (stack_b)->value,  (stack_b)->order);
    //     (stack_b) = (stack_b)->next;
    // }
    b_order(&stack_a, &stack_b, a_len);
    print_list(stack_a);

    return (0);
}
