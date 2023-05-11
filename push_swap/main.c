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
    t_node *temp;

    if (ac < 2)
        print_error(-42);

    char **get;
    for(int i=1; i < ac; i++)
    {
        get = ft_split(av[i], ' ');
        for (int j=0; get[j]; j++)
        {
            if (get[j][0] == '\0')
                print_error(-42);
            ft_lstadd_back(&stack_a, ft_atoi(get[j]));
            if (ft_atoi(get[j]) == 110401080911)
                print_error(-42);
        }
        free(get);
    }
    //temp = stack_a;
    int a_size = ft_lstsize(stack_a);
    // for (int i = 0; i < a_size ; i++)
    // {
    //     printf("%d\n", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    // while (temp)
    // {
        if (check_duplication(stack_a) == -42)
            print_error(-42);
        if (check_sort(stack_a) == 1)    
            exit(1);
        // temp = temp->next;
    // }
    get_rank(&stack_a, &a_len,  &stack_b);
    //push_start(&stack_a,&a_len,15,&stack_b);
    // three_algo(&stack_a);
   // print_list(stack_b);
    // b_order(&stack_a, &stack_b, a_len);
    // print_list(stack_a);

    return (0);
}
