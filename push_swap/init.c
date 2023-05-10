#include "push_swap.h"

t_node  *create_node(int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}


void	ft_lstadd_back(t_node **lst, int value)
{
	t_node	*temp;
	t_node *new;

	new = create_node(value);
	temp = *lst;
	if (!lst || !new)
		return ;
	else if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
		(*lst) = temp;
	}
}


// void    add_node(t_node **head, int value)
// {
//     t_node  *new_node;

//     new_node = create_node(value);
//     if (!new_node)
//         return ;
//     if (*head == NULL)
//         *head = new_node;
//     else
//     {
//         new_node->next = *head;
//         *head = new_node;
//     }
// }

int	ft_lstsize(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	temp = str;
	if (!temp)
		return (NULL);
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (str);
}
