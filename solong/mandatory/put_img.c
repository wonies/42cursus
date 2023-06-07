/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:38:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/07 16:43:57 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_map *map, int x, int y, char *file)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->win, img, y * 50, x * 50);
	mlx_destroy_image(map->mlx, img);
}

void	base_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(map->mlx, map->win);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			put_img(map, y, x, "../pic/base.xpm");
			x++;
		}
		y++;
	}
}

void	place_images(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->mapping[y][x] == 'P')
				put_img(map, y, x, "../pic/kerbi.xpm");
			else if (map->mapping[y][x] == 'C')
				put_img(map, y, x, "../pic/toma.xpm");
			else if (map->mapping[y][x] == '1')
				put_img(map, y, x, "../pic/obstacle.xpm");
			else if (map->mapping[y][x] == 'E')
				put_img(map, y, x, "../pic/exit.xpm");
			x++;
		}
		y++;
	}
}

int	show_map(t_map *map)
{
	base_map(map);
	place_images(map);
	return (0);
}
