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
	int		order;
	t_node	*next;
};

typedef struct s_info
{
	int		size;
	int		chunk;
} t_info;

int     print_error(int err);
char	**ft_split(char const *s, char c);

/* parsing */
char    **parsing(t_node **a, int ac, char **av);

/* lst */
t_node  *create_node(int value);
void    ft_lstadd_back(t_node **lst, int value);
int     ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);

/* init */
int     ft_strlen(char const *s);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

/* ft_atoi */
long	ft_atoi(const char *str);

/* check */
int     check_duplication(t_node *a);
int     check_sort(t_node *a);

/* start */
void    pushswap_start(t_node *a, t_node *b, t_info *info);

/* order1 */
void    sa(t_node *a);
void    sb(t_node *b);
void    ss(t_node *a, t_node *b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

/* order2 */
void    ra(t_node **head);
void    rb(t_node **head);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);

/* order3 */
void    rrr(t_node **a, t_node **b);

/* getting */
int     create_chunk(t_node **a, t_info *info);
void    get_chunk(t_node **a, t_node **b, t_info *info);
void    get_order(t_node **a, t_info *info);

/* handmade */
void    three_times(t_node **a);
void    five_times(t_node **a, t_node **b);
void    handmade_count(t_node **a, t_node **b, int size);

/* sort_a */
void    put_sort(t_node **a, t_node **b, int size, int chunk);
int     optimize(t_node **a, int size);

/* sort_b */
void    sort_b(t_node **a, t_node **b, int size);
void    b_order(t_node **a, t_node **b, int size);
int     find_order(t_node **b, int size, int len);

#endif