#include "../pipex.h"

void    read_gnl(t_pipe *pp)
{
    char    *str;

    str = get_next_line(0);
    while (str)
    {
        write(pp->infile, str, ft_strlen(str));
        if (strncmp(str, pp->limiter, pp->limiter_len) == 0)
            return ;
        str = get_next_line(0);
    }
    close(pp->infile);
}