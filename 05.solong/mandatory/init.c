/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:31:09 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/13 15:41:45 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_long(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len-- > 0)
		*temp++ = (unsigned char)c;
	return (b);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	while ((*s1_cpy || *s2_cpy) && n > 0)
	{
		if (*s1_cpy != *s2_cpy || n == 0)
			return (*s1_cpy - *s2_cpy);
		s1_cpy++;
		s2_cpy++;
		n--;
	}
	return (0);
}
