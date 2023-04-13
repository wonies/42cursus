/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:16:40 by wonhshin          #+#    #+#             */
/*   Updated: 2023/04/13 15:16:41 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;
	int		i;

	i = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

int	ft_strchr(char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (!str)
		return (-2);
	while (str[i] && (str[i] != ch))
		i++;
	if (str[i] == ch)
		return (i);
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*string;
	int		size;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
	else
		size = len;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	while (i < len && s[start])
		string[i++] = s[start++];
	string[i] = '\0';
	return (string);
}

char	*setting_data(char *str)
{
	if (str == NULL)
	{
		str = (char *)malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
