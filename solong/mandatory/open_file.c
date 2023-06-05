#include "so_long.h"

void    open_file(t_map *map, char **av)
{
    t_list  *head;
    int     fd;
    char    *filename;
    int     len;
    
    head = NULL;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        error_msg(-4);
    filename = av[1];
    len = ft_strlen_long(filename);
    if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
        error_msg(-4);
    head = read_map(fd);
    map->height = ft_lstsize(head);
    map->width = ft_strlen(head->content) - 1;
    map_init(map);
    map_setting(map, head);
}
