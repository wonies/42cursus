#include "../pipex.h"

void    read_gnl(t_pipe *pp)
{
    char    *str;

    str = get_next_line(0);
    if (!str)
        return ;
    if (strncmp(str, pp->limiter, pp->limiter_len) == 0)
    {
        free(str);
        return ;
    }
    while (str)
    {
        if (strncmp(str, pp->limiter, pp->limiter_len) == 0)
        {
            free(str);
            break ;
        }
        write(pp->infile, str, ft_strlen(str));
        free(str);
        str = get_next_line(0);
    }
    printf("infile : %d\n", pp->infile);
    close(pp->infile);
    pp->infile = open(HEREDOC, O_RDONLY);
}

