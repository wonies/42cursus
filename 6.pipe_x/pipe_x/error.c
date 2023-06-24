#include "pipex.h"

void    error_msg(char *msg)
{
    perror(msg);
    exit(1);
}
