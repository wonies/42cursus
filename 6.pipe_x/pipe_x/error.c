#include "pipex.h"

void    error_msg(int flag)
{
    if (flag == 1)
        perror("not valid!\n");
    else if (flag == 2)
        perror("Failed to open out file\n");
    exit(1);
}

void    error_msg_c(char *err)
{
    perror(err);
    exit(1);
}