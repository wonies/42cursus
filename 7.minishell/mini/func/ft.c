#include "../includes/minishell.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	size;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
	else
		size = len;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string || !s)
		return (NULL);
	if (size)
		while (i < len && s[start])
			string[i++] = s[start++];
	string[i] = '\0';
	return (string);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
