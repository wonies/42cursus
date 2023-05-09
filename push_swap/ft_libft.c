#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int			sign;
	long			res;
	size_t		i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13) || str[i] == '-' || str[i] == '+' || (str[i] >= '0' \
	&& str[i] <= '9') || str[i] == '\"'))
		return 110401080911;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
    if (res * sign > 2147483647 || res * sign < -2147483648)
        return 110401080911;
	return (sign * res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, count * size);
	return (temp);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len-- > 0)
		*temp++ = (unsigned char)c;
	return (b);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
