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
    int height;
    int width;

} t_map;

#endif
