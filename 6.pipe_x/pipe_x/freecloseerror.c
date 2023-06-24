#include "pipex.h"

void    error_msg(char *msg)
{
    perror(msg);
    exit(1);
}

void    close_all(t_pipe *pp)
{
    close(pp->infile);
    close(pp->outfile);
    if (pp->infile < 0)
        exit(1);
}

void free_all(t_pipe *pp)
{
    int i;

    i = 0;
    while (pp->str[i])
    {
        free(pp->str[i]);
        i++;
    }
    free(pp->fd_path);
    free(pp->str);
    free(pp->com);
    close_all(pp);
}
