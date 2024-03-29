/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:06:30 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/18 22:06:31 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*data_join(char **data, char *buf)
{
	char	*temp;

	if (*data)
	{
		temp = *data;
		*data = ft_strjoin(*data, buf);
		free(temp);
		temp = NULL;
	}
	if (!*data)
		return (NULL);
	return (*data);
}

char	*devide_line(char **data, int idx)
{
	char	*line;
	char	*data_new;

	data_new = NULL;
	idx = ft_strchr(*data, '\n');
	line = ft_substr(*data, 0, idx + 1);
	if (line)
	{
		data_new = ft_substr(*data, idx + 1, ft_strlen_g(*data));
		if (!data_new)
		{
			free(line);
			free(*data);
			*data = NULL;
			return (NULL);
		}
	}
	free(*data);
	*data = data_new;
	return (line);
}

char	*size_is_zero(char **data, int idx)
{
	char	*line;

	idx = ft_strchr(*data, '\n');
	if (idx != -1)
		return (devide_line(data, 0));
	line = ft_substr(*data, 0, ft_strlen_g(*data));
	if (!line)
	{
		free(*data);
		*data = NULL;
		return (NULL);
	}
	if (ft_strlen_g(*data) <= 0 || *line == '\0')
	{
		free(line);
		line = NULL;
	}
	free(*data);
	*data = NULL;
	return (line);
}

char	*read_buf(int fd, char **data, char *buf, int size)
{
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		*data = setting_data(*data);
		if (size == 0)
			return (size_is_zero(data, 0));
		buf[size] = '\0';
		*data = data_join(data, buf);
		if (!*data)
			return (NULL);
		if (ft_strchr(*data, '\n') != -1)
			return (devide_line(data, 0));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(data);
		data = NULL;
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(data);
		data = NULL;
		return (NULL);
	}
	line = read_buf(fd, &data, buf, 1);
	free(buf);
	return (line);
}
