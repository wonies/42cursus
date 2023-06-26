#include "pipex.h"

void    infile_errmsg(t_pipe *pp, char **av)
{
    if (pp->infile < 0)
	{
		write(1, av[1], ft_strlen(av[1]));
		write(1, ": No such file or directory\n", 28);
	}
}

void    error_msg(char *msg)
{
    perror(msg);
    exit(1);
}

void    close_all(t_pipe *pp)
{
    if (pp->infile < 0)
        exit(1);
    close(pp->infile);
    close(pp->outfile);
}

void free_all(t_pipe *pp)
{
    int i;

    close_all(pp);
    i = 0;
    while (pp->str[i])
    {
        free(pp->str[i]);
        i++;
    }
    free(pp->fd_path);
    free(pp->str);
    free(pp->com);
}
