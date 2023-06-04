#include "so_long.h"

void    square_check(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->mapping[i][j] == 'P')
            {
                map->player[0] = i;
                map->player[1] = j;
            }
            j++;
        }
        i++;
    }
}