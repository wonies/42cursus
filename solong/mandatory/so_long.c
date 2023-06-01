#include "so_long.h"

void    param_init(t_param *param)
{
    param->x = 3;
    param->y = 4;
}

int key_press(int key, t_param *param)
{
    static int a = 0;

    if (key == KEY_W)
        param->y++;
    else if (key == KEY_S)
        param->y--;
    else if (key == KEY_A)
        param->x--;
    else if (key == KEY_D)
        param->x++;
    else if (key == KEY_ESC)
        exit(0);
    printf("x : %d, y: %d\n", param->x, param->y);
    return 0;
}


t_list  *read_map(int fd)
{
    t_list  *head;
    t_list  *new;
    char    *str;

    head = NULL;
    str = get_next_line(fd);
    if (!str)
    {
        close(fd);
    }
    while (str)
    {
        printf("%s\n", str);
        new = ft_lstnew(str);
        ft_lstadd_back(&head, new);
        str = get_next_line(fd);
    }
    close(fd);
    return head;
}


void    map_setting(t_map *map)
{
    char    **
}



void    map_init(t_map *map)
{
    char    **mapping;

    mapping = map->mapping;
    mapping = (char **)(ft_calloc(sizeof(map->height), 1));
}

void    open_file(t_map *map, char **av)
{
    t_list  *head;
    int     fd;
    char    *filename;
    int     len;
    
    head = NULL;
    fd = open(av[1], O_RDONLY);
    printf("fd : %d\n", fd);
    if (fd < 0)
        printf("1");
    head = read_map(fd);
    map->height = ft_lstsize(head);
    map->width = ft_strlen(head->content) - 1;
    printf("map height : %d\n", map->height);
    printf("map width : %d\n", map->width);
   // map_init(map);
}

int main(int ac, char **av)
{
    // void    *mlx_ptr;
    // void    *win_ptr;

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, 500, 500, "wonie");
    // mlx_loop(mlx_ptr);

    // t_list *lst;
    t_map map;
    
    initialize_structure(&map);
    open_file(&map, av);
}

//gcc -L ../mlx -lmlx -framework OpenGL -framework Appkit -lz so_long.c