/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:44:02 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/08 01:45:16 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_setting(t_map *map, t_list *head)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->mapping[i] = ft_strdup(head->content);
		map->map_cpy[i] = ft_strdup(head->content);
		map->map_cpy2[i] = ft_strdup(head->content);
		if (!(map->mapping[i]) || !(map->map_cpy[i]) || !(map->map_cpy2[i]))
			error_msg(-4);
		head = head->next;
		i++;
	}
	if (find_character(map) > 1 || find_character(map) == 0)
		error_msg(-1);
	if (find_exit(map) > 1 || find_exit(map) == 0)
		error_msg(-2);
	if (find_collect(map) == 0)
		error_msg(-3);
}

void	map_init(t_map *map)
{
	map->mapping = (char **)(ft_calloc(map->height, sizeof(char *)));
	map->map_cpy = (char **)(ft_calloc(map->height, sizeof(char *)));
	map->map_cpy2 = (char **)(ft_calloc(map->height, sizeof(char *)));
	if (!(map->mapping) || !(map->map_cpy) || !(map->map_cpy2))
			error_msg(-4);
}

t_list	*read_map(int fd)
{
	t_list	*head;
	t_list	*new;
	char	*str;

	head = NULL;
	str = get_next_line(fd);
	if (!str)
	{
		close(fd);
	}
	while (str)
	{
		new = ft_lstnew(str);
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	close(fd);
	return (head);
}
