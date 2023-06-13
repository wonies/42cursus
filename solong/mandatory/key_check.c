/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:32:52 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/09 17:35:05 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_map *map)
{
	int	i;
	int	j;

	i = map->player[0];
	j = map->player[1];
	if (map->mapping[i - 1][j] != '1' && map->mapping[i - 1][j] != 'E')
	{
		if (map->mapping[i - 1][j] == 'C')
			map->collect--;
		map->player[0] = i - 1;
		map->mapping[i - 1][j] = 'P';
		map->mapping[i][j] = '0';
		map->step_cnt++;
	}
	if (map->mapping[i - 1][j] == 'E' && map->collect == 0)
		exit(0);
	show_map(map);
}

void	key_down(t_map *map)
{
	int	i;
	int	j;

	i = map->player[0];
	j = map->player[1];
	if (map->mapping[i + 1][j] != '1' && map->mapping[i + 1][j] != 'E')
	{
		if (map->mapping[i + 1][j] == 'C')
			map->collect--;
		map->player[0] = i + 1;
		map->mapping[i + 1][j] = 'P';
		map->mapping[i][j] = '0';
		map->step_cnt++;
	}
	if (map->mapping[i + 1][j] == 'E' && map->collect == 0)
		exit(0);
	show_map(map);
}

void	key_left(t_map *map)
{
	int	i;
	int	j;

	i = map->player[0];
	j = map->player[1];
	if (map->mapping[i][j - 1] != '1' && map->mapping[i][j - 1] != 'E')
	{
		if (map->mapping[i][j - 1] == 'C')
			map->collect--;
		map->mapping[i][j - 1] = 'P';
		map->mapping[i][j] = '0';
		map->player[1] = j - 1;
		map->step_cnt++;
	}
	if (map->mapping[i][j - 1] == 'E' && map->collect == 0)
		exit(0);
	show_map(map);
}

void	key_right(t_map *map)
{
	int	i;
	int	j;

	i = map->player[0];
	j = map->player[1];
	if (map->mapping[i][j + 1] != '1' && map->mapping[i][j + 1] != 'E')
	{
		if (map->mapping[i][j + 1] == 'C')
			map->collect--;
		map->mapping[i][j + 1] = 'P';
		map->mapping[i][j] = '0';
		map->player[1] = j + 1;
		map->step_cnt++;
	}
	if (map->mapping[i][j + 1] == 'E' && map->collect == 0)
		exit(0);
	show_map(map);
}

int	key_press(int key, t_map *map)
{
	int	cnt;

	cnt = map->step_cnt;
	if (key == KEY_W)
		key_up(map);
	else if (key == KEY_S)
		key_down(map);
	else if (key == KEY_A)
		key_left(map);
	else if (key == KEY_D)
		key_right(map);
	else if (key == KEY_ESC)
		exit(0);
	if (cnt != map->step_cnt)
		key_hook(map);
	return (0);
}
