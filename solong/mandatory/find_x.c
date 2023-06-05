#include "so_long.h"

int    find_exit(t_map *map)
{
    int i;
    int j;
    int exit_flag;

    i = 0;
    exit_flag = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->mapping[i][j] == 'E')
            {
                map->gameover[0] = i;
                map->gameover[1] = j;
                exit_flag++;
            }
            j++;
        }
        i++;
    }
    return (exit_flag);
}

int   find_collect(t_map *map)
{
    int i;
    int j;
    int collect;

    i = 0;
    collect = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->mapping[i][j] == 'C')
            {
                map->collect++;
                map->cpy2++;
            }
            j++;
        }
        i++;
    }
    collect = map->collect;
    return (collect);
}

int    find_character(t_map *map)
{
    int i;
    int j;
    int character_flag;

    i = 0;
    character_flag = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->mapping[i][j] == 'P')
            {
                map->player[0] = i;
                map->player[1] = j;
                character_flag++;
            }
            j++;
        }
        i++;
    }
    return (character_flag);
}
