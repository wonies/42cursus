/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:04 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 15:14:05 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
