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

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "wonie");
    mlx_loop(mlx_ptr);
}

