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
    close(pp->infile);
    pp->infile = open(HEREDOC, O_RDONLY);
}

void    fileinit_bonus(int ac, char **av, t_pipe *pp)
{
    pp->infile = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pp->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
    if (pp->outfile < 0)
        error_msg("CANT OPEN OUTFILE\n");
    pp->child = ac - 4;
    pp->limiter = av[2];
    if (!pp->limiter)
        error_msg("NO LIMITER\n");
    pp->limiter_len = ft_strlen(pp->limiter);
    pp->com = (t_pid *)ft_calloc(pp->child, sizeof(t_pid));
    if (!pp->com)
        error_msg("CANT READ LIMITER\n");
    pp->fd_path = NULL;
    pp->str = NULL;
}
