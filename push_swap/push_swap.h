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

void	add_node(t_node **list, int value);
void sa(t_node *a);
void	sb(t_node *b);
void 	ss(t_node *a, t_node *b);
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
int    create_chunk(t_node **a, t_info *info);
void    get_rank(t_node **a, t_info *info);
void    get_order(t_node **a, t_info *info);
t_node  *create_node(int value);
void    push_start(t_node **a, t_info *info, int chunk, t_node **b);
void    b_order(t_node **a, t_node **b, t_info info);
long	ft_atoi(const char *str);
int check_duplication(t_node *a);
long long   b_max(t_node **b);
int b_max_order(t_node **b, long long max);
int check_sort(t_node *a);
size_t	count_str(char const *s, char c);
char	**ft_free_split(char **str, int order);
size_t	str_len(char const *s, char c);
char	*put_word(char const *s, char c);
char	**ft_split(char const *s, char c);
int	ft_strlen(char const *s);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void    three_algo(t_node **a);
void count_each(t_node **a, t_info *info);
t_node	*ft_lstlast(t_node *lst);


#endif
