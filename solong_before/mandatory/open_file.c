/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:37:47 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/09 16:23:24 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_file(t_map *map, char **av)
{
	t_list	*head;
	int		fd;
	char	*filename;
	int		len;

	head = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_msg(-4);
	filename = av[1];
	len = ft_strlen_long(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
		error_msg(-4);
	head = read_map(fd);
	if (!head)
		error_msg(-4);
	map->height = ft_lstsize(head);
	map->width = ft_strlen(head->content) - 1;
	map_init(map);
	map_setting(map, &head);
}
