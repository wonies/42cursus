/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:32:08 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/13 23:26:32 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs_init(t_map *map)
{
	map->check_x[0] = -1;
	map->check_x[1] = 1;
	map->check_x[2] = 0;
	map->check_x[3] = 0;
	map->check_y[0] = 0;
	map->check_y[1] = 0;
	map->check_y[2] = -1;
	map->check_y[3] = 1;
}

void	initialize_structure(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->collect = 0;
	map->mapping = NULL;
	map->map_cpy = NULL;
	map->map_cpy2 = NULL;
	map->cpy = 1;
	map->cpy2 = 0;
	map->step_cnt = 0;
	map->player[0] = 0;
	map->player[1] = 0;
	map->gameover[0] = 0;
	map->gameover[1] = 0;
	dfs_init(map);
}
