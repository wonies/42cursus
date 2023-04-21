#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_node	t_node;

struct	s_node
{
	int		value;
	t_node	*next;
};

t_node	*create_node(int value);
void	add_node(t_node **list, int value);
void    sa(t_node *(a));
void sb(t_node *b);
void ss(t_node *a, t_node *b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);
void    ra(t_node **head);
void    rb(t_node **head);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);
int print_error(int err);
int	ft_lstsize(t_node *lst);
void    create_rank(t_node **a);
#endif
