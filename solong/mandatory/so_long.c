/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:51:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/08 23:55:43 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
    t_map map;

    // atexit(leaks);
    if (ac != 2)
        error_msg(-4);
    initialize_structure(&map);
    open_file(&map, av);
	printf("7---------------\n");
	system("leaks a.out");
    // map.mlx = mlx_init();
    // map.win = mlx_new_window(map.mlx, map.width * 50, map.height * 50, "wonie");
    // mapcheck_validate(&map);
    // show_map(&map);
    // mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
    // mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_e, &map);
    // mlx_loop(map.mlx);
}
