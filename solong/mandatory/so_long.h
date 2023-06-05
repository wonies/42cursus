#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS      2
# define X_EVENT_KEY_RELEASE    3
# define KEY_ESC                53
# define KEY_W                  13
# define KEY_A                  0
# define KEY_S                  1
# define KEY_D                  2

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

typedef struct s_param
{
    int     x;
    int     y;
} t_param;


typedef struct s_list
{
    char    *content;
    struct s_list *next;
} t_list;

typedef struct s_map
{
    int     height;
    int     width;
    char    **mapping;
    void    *mlx; // mlx라는 걸 쓰는데, 이 함수의 반환형이 보이드형 포인트임
    void    *win;
    int     player[2];
    int     gameover[2];
    int     collect;
    int     check_x[4];
    int     check_y[4];
    char    **mapping_cpy;
    char    **mapping_cpy2;
    int     cpy;
    int     cpy2;

} t_map;

void    open_file(t_map *map, char **av);

/* lst.c */
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);


/* init.c */
size_t	ft_strlen_long(const	char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);

/* initialize.c */
void    initialize_structure(t_map *map);

/* put_img*/
void    put_img(t_map *map, int x, int y, char *file);
void    base_map(t_map *map);
void    place_image(t_map *map);
int     show_map(t_map *map);

/* error.c */
void    error_msg(int flag);

/* check_validate */
void    square_check(t_map *map);
void    check_write_validate(t_map *map);
void    check_square_obstacle(t_map *map);
void    mapcheck_through_bfs(t_map *map);


#endif
