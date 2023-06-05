#include "so_long.h"

void    square_check(t_map *map)
{
    int i;
    int len;

    i = 0;
    len = (map->width) + 1;
    while (i < (map->height) - 1)
    {
        if (ft_strlen_long(map->mapping[i]) != len)
            error_msg(-4);
        i++;
    }
    if (ft_strlen_long(map->mapping[i]) != len - 1)
        error_msg(-4);
}

void    check_write_validate(t_map *map)
{
    int     i;
    int     j;
    char    alpha;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            alpha = map->mapping[i][j];
            if (alpha != 'P' && alpha != 'E' && alpha != '0' && alpha != '1' && alpha != 'C')
                error_msg(-4);
            j++;
        }
        i++;
    }
}

void    check_square_obstacle(t_map *map)
{
    int check_height;
    int check_width;
    char    alpha;
    int i;
    int j;

    i = 0;
    check_height = map->height  - 1;
    check_width = map->width - 1;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            alpha = map->mapping[i][j];
            if (i == 0 || i == check_height || j == 0 || j == check_width)
            {
                if (alpha != '1')
                    error_msg(-4);
            } 
            j++;
        }
        i++;
    }
    
}

void    mapcheck_validate(t_map *map)
{
    square_check(map);
    check_write_validate(map);
    check_square_obstacle(map);
    onecase_dfs(map->player[0], map->player[1], map);
    twocase_dfs(map->player[0], map->player[1], map);
    if (map->cpy != 0 || map->cpy2 != 0)
        error_msg(-4);
}
