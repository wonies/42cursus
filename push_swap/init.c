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

void    add_node(t_node **head, int value)
{
    t_node  *new_node;

    new_node = create_node(value);
    if (!new_node)
        return ;
    if (*head == NULL)
        *head = new_node;
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

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
