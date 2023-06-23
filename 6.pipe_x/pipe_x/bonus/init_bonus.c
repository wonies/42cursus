#include "../pipex.h"

void    fileinit_bonus(int ac, char **av, t_pipe *pp)
{
    pp->infile = open("HEREDOC", O_WRONLY | O_CREAT);
    if (pp->infile < 0) 
    {
        perror("Failed to open input file\n");
        exit(1);
    }
    pp->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
    if (pp->outfile < 0)
    {
        perror("Failed to open out file\n");
        exit(1);
    }
    pp->child = ac - 4;
    pp->limiter = av[2];
    
    pp->com = (t_pid *)ft_calloc(pp->child, sizeof(t_pid));
}
