/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:02:50 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/13 18:21:21 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	onecase_dfs(int x, int y, t_map *map)
{
	int		nx;
	int		ny;
	int		i;

	i = 0;
	map->map_cpy[x][y] = '1';
	while (i < 4)
	{
		nx = x + map->check_x[i];
		ny = y + map->check_y[i];
		if (nx < 0 || nx > map->height || ny < 0 || ny > map->width)
			continue ;
		if (map->map_cpy[nx][ny] == 'E' || map->map_cpy[nx][ny] == '0' ||
			map->map_cpy[nx][ny] == 'C' || map->map_cpy[nx][ny] == 'P')
		{
			if (map->map_cpy[nx][ny] == 'E')
				map->cpy--;
			onecase_dfs(nx, ny, map);
		}
		i++;
	}
}

void	twocase_dfs(int x, int y, t_map *map)
{
	int		nx;
	int		ny;
	int		i;

	i = 0;
	map->map_cpy2[x][y] = '1';
	while (i < 4)
	{
		nx = x + map->check_x[i];
		ny = y + map->check_y[i];
		if (nx < 0 || nx > map->height || ny < 0 || ny > map->width - 1)
			continue ;
		if (map->map_cpy2[nx][ny] == '0' || map->map_cpy2[nx][ny] == 'P' ||
			map->map_cpy2[nx][ny] == 'C')
		{
			if (map->map_cpy2[nx][ny] == 'C')
				map->cpy2--;
			twocase_dfs(nx, ny, map);
		}
		i++;
	}
}
