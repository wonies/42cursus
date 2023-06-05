#include "so_long.h"

// void    player_init(t_map *map)
// {
//     map->player[0] ;
// }

void    key_up(t_map *map)
{
    int i;
    int j;
    
    i = map->player[0];
    j = map->player[1];
    if (map->mapping[i-1][j] != '1' && map->mapping[i-1][j] != 'E')
    {
        if (map->mapping[i-1][j] == 'C')
            map->collect--;
        map->player[0] = i-1;
        map->mapping[i-1][j] = 'P';
        map->mapping[i][j] = '0';
        // map->player[1] = i-1;
    }
    if (map->mapping[i-1][j] == 'E' && map->collect == 0)
        exit(0);
    show_map(map);
}

void    key_down(t_map *map)
{
    int i;
    int j;
    
    i = map->player[0];
    j = map->player[1];
    if (map->mapping[i+1][j] != '1' && map->mapping[i+1][j] != 'E')
    {
        if (map->mapping[i+1][j] == 'C')
            map->collect--;
        map->player[0] = i+1;
        map->mapping[i+1][j] = 'P';
        map->mapping[i][j] = '0';
        // map->player[1] = j-1;
    }
    if (map->mapping[i+1][j] == 'E' && map->collect == 0)
        exit(0);
    show_map(map);
}

void    key_left(t_map *map)
{
    int i;
    int j;
    
    i = map->player[0];
    j = map->player[1];
    if (map->mapping[i][j-1] != '1' && map->mapping[i][j-1] != 'E')
    {
        if (map->mapping[i][j-1] == 'C')
            map->collect--;
        map->mapping[i][j-1] = 'P';
        map->mapping[i][j] = '0';
        map->player[1] = j-1;
        // map->player[1] = j;
    }
    if (map->collect == 0)
        printf("all : %d\n", map->collect);

    if (map->mapping[i][j-1] == 'E' && map->collect == 0)
        exit(0);
    show_map(map);
}

void    key_right(t_map *map)
{
    int i;
    int j;
    
    i = map->player[0];
    j = map->player[1];
    if (map->mapping[i][j+1] != '1' && map->mapping[i][j+1] != 'E')
    {
        if (map->mapping[i][j+1] == 'C')
            map->collect--;
        map->mapping[i][j+1] = 'P';
        map->mapping[i][j] = '0';
        map->player[1] = j+1;
        //map->player[1] = j;
    }
    if (map->mapping[i][j+1] == 'E' && map->collect == 0)
        exit(0);
    show_map(map);
}

int key_press(int key, t_map *map)
{
    static int a = 0;

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
                printf("char : %d\n", character_flag);
            }
            j++;
        }
        i++;
    }
    return (character_flag);
}

void    map_setting(t_map *map, t_list *head)
{
    int     i;

    i = 0;
    while (i < map->height)
    {
       map->mapping[i] = ft_strdup(head->content);
       map->mapping_cpy[i] = ft_strdup(head->content);
       map->mapping_cpy2[i] = ft_strdup(head->content);
       head = head->next;
       printf("%s\n", map->mapping[i]);
       i++;
    }
    if (find_character(map) > 1 || find_character(map) == 0)
        error_msg(-1);
    if (find_exit(map) > 1 || find_exit(map) == 0)
        error_msg(-2);
    if (find_collect(map) == 0)
        error_msg(-3);
    printf("map collect : %d\n", map->collect);
}

void    map_init(t_map *map)
{
    map->mapping = (char **)(ft_calloc(map->height, sizeof(char *)));
    map->mapping_cpy = (char **)(ft_calloc(map->height, sizeof(char *)));
    map->mapping_cpy2 = (char **)(ft_calloc(map->height, sizeof(char *)));
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
        error_msg(-4);
    filename = av[1];
    len = ft_strlen_long(filename);
    if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
        error_msg(-4);
    head = read_map(fd);
    map->height = ft_lstsize(head);
    map->width = ft_strlen(head->content) - 1;
    printf("map height : %d\n", map->height);
    printf("map width : %d\n", map->width);
    map_init(map);
    map_setting(map, head);
   // map_init(map);
}

int main(int ac, char **av)
{
    // void    *mlx_ptr;
    // void    *win_ptr;
    // mlx_loop(mlx_ptr);

    // t_list *lst;
    t_map map;
    
    initialize_structure(&map);
    open_file(&map, av);
    map.mlx = mlx_init();
    map.win = mlx_new_window(map.mlx, map.width * 50, map.height * 50, "wonie");
    square_check(&map);
    check_write_validate(&map);
    check_square_obstacle(&map);
    mapcheck_through_bfs(&map);
    show_map(&map);
    mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
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

