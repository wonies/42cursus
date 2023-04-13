/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:00:12 by wonhshin          #+#    #+#             */
/*   Updated: 2023/04/13 14:44:11 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*setting_data(char **data)
{
	if (*data == NULL)
	{
		*data = (char *)malloc(BUFFER_SIZE + 1);
		if (!*data)
			return (NULL);
		*data[0] = '\0';
	}
	return (*data);
}

char    *devide_line(char **data, int idx, int flag)
{
    char    *line;
    char    *data_new;

    data_new = NULL;
    // if (!(*data))
    // {
    //     free(*data);
    //     *data = NULL;
    //     return (NULL);
    // }
    idx = ft_strchr(*data, '\n');
    line = ft_substr(*data, 0, idx + 1);
    if (line)
    {
        data_new = ft_substr(*data, idx + 1, ft_strlen(*data));
        if (!data_new)
            flag = 1;
    }
    else
        line = NULL;
    if (*data)
        free(*data);
    if (flag == 0)
        *data = data_new;
    return (line);
}


char    *size_is_zero(char **data, int idx)
{
    char    *line;

    idx = ft_strchr(*data, '\n');
    if (idx != -1)
        return devide_line(data, 0, 0);
    line = ft_substr(*data, 0, ft_strlen(*data));
    if (!line)
    {
        free(*data);
        *data = NULL;
        return (NULL);
    }
    if (ft_strlen(*data) <= 0 || *line == '\0')
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
		setting_data(data);
		if (size == 0)
			return (size_is_zero(data, 0));
		buf[size] = '\0';
		if (!(*data = data_join(data, buf)))
			return (NULL);
		// if (*data)
		// {
		// 	temp = *data;
		// 	*data = ft_strjoin(*data, buf);
		// 	free(temp);
		// 	temp = NULL;
		// }
		// if (!*data)
		// 	return (NULL);
		if (ft_strchr(*data, '\n') != -1)
			return (devide_line(data, 0, 0));
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	static char	*data = NULL;
	char		*buf;
	char		*line;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (data)
		{
			free(data);
			data = NULL;
		}
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	line = read_buf(fd, &data, buf, size);
	free(buf);
	buf = NULL;
	return (line);
}