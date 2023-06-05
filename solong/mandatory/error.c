#include "so_long.h"

void    error_msg(int flag)
{
    if (flag == -1)
    {
        write(2, "Error\n", 6);
        write(2, "Player is NOT ONLY ONE!!\n", 25);
    }
    else if (flag == -2)
    {
        write(2, "Error\n", 6);
        write(2, "Exit is NOT ONE!!\n", 18);
    }
    else if (flag == -3)
    {
        write(2, "Error\n", 6);
        write(2, "Feed is NOT EXIST!!\n", 20);
    }
    else if (flag == -4)
    {
        write(2, "Error\n", 6);
        write(2, "NOT VALIDATE!!!\n", 16);
    }
    exit(1);
}