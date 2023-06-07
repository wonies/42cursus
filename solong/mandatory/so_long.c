/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:51:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/07 18:13:05 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()
{
	system("leaks checker");
}


int main(int ac, char **av)
{
    t_map map;
    
    atexit(leaks);
    if (ac != 2)
        error_msg(-4);
    initialize_structure(&map);
    open_file(&map, av);
    map.mlx = mlx_init();
    map.win = mlx_new_window(map.mlx, map.width * 50, map.height * 50, "wonie");
    mapcheck_validate(&map);
    show_map(&map);
    mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
    mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_e, &map);
    //mlx_key_hook(map.win, &key_press, &map);
    mlx_loop(map.mlx);
}

//mlx_hook -> key press & key release 차이 설정가능
//gcc -L ../mlx -lmlx -framework OpenGL -framework Appkit -lz so_long.c




//1. 사각형인지 확인 
//2. 10CPE 다른 문자시 에러처리
//3. 장애물 1인지
//4. 맵유효성검사
//5. .ber파일로 무조건들어오기!! 

