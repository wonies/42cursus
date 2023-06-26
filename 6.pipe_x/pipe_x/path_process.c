#include "pipex.h"

void    close_fd(int i, t_pipe *pp)
{
    if (i == 0)
        close(pp->com[i].pipe_fd[1]);
    else if (i == pp->child -1)
        close(pp->com[i - 1].pipe_fd[0]);
    else
    {
        close(pp->com[i - 1].pipe_fd[0]);
        close(pp->com[i].pipe_fd[1]);
    } 
}
// void    process_transp(int i, t_pipe *pp)
// {
//     printf("process idx : %d\n", i);
//     if (i == 0)
//     {
//         printf("---check procees idx!!---\n");
//         if ((close(pp->com[i].pipe_fd[0]) < 0) \
//         || (dup2(pp->infile, STDIN_FILENO)) < 0)
//             error_msg("i == 0 || WRONG!!!\n");
//     }
//     else if (i == (pp->child) - 1)
//     {
//         if ((dup2(pp->com[i - 1].pipe_fd[0], STDIN_FILENO) < 0))
//             error_msg("i == pp->child -1 || WRONG!!!\n");
//     }
//     else
//     {
//         if ((close(pp->com[i].pipe_fd[0]) < 0) \
//         || (dup2(pp->com[i - 1].pipe_fd[0],STDIN_FILENO) < 0))
//             error_msg("i == else || WRONG!!\n");
//     }
// }

void    process_transp(int i, t_pipe *pp)
{
    if (i == 0)
    {
        if ((close(pp->com[i].pipe_fd[0]) < 0) \
        || (dup2(pp->com[i].pipe_fd[1], STDOUT_FILENO) < 0)  \
        || (dup2(pp->infile, STDIN_FILENO)) < 0)
            error_msg("WRONG!!!\n");
    }
    else if (i == pp->child - 1)
    {
        if ((dup2(pp->com[i - 1].pipe_fd[0], STDIN_FILENO) < 0) \
        || (dup2(pp->outfile, STDOUT_FILENO) < 0))
            error_msg("WRONG!!!\n");
    }
    else
    {
        if ((close(pp->com[i].pipe_fd[0]) < 0) \
        || (dup2(pp->com[i - 1].pipe_fd[0],STDIN_FILENO) < 0) \
        || (dup2(pp->com[i].pipe_fd[1], STDOUT_FILENO)) < 0)
            error_msg("WRONG!!\n");
    }
}

void    wait_child(t_pipe *pp)
{
    int i;

    i = 0;
    while (i++ < pp->child)
        waitpid(-1, 0, 0);
}

void    cmd_split(int i, t_pipe *pp, char **av)
{
    printf("check : %d\n", pp->check);
    printf("idx : %d\n", i);
    if (pp->check == 114)
        pp->cmd = ft_split(av[i + 3], ' ');
    else
        pp->cmd = ft_split(av[i + 2], ' ');
    printf("cmd split : %s\n", pp->cmd[0]);
}

void    execute(t_pipe *pp, char **av)
{
    int i;

    i = 0;
    while (i < pp->child)
    {
        if (i < pp->child - 1)
            if (pipe(pp->com[i].pipe_fd) < 0)
                error_msg("PIPE FAIL!\n");
        if ((pp->com[i].pid = fork()) < 0)
            error_msg("FORK FAIL!\n");
        if (pp->com[i].pid == 0)
        {
            process_transp(i, pp);
            cmd_split(i, pp, av);
            isok_access(pp);
            if (execve(pp->fd_path, pp->cmd, pp->env) < 0)
                error_msg("EXE FAIL!(LOST CHILD)\n");
        }
        close_fd(i, pp);
        i++;
    }
    wait_child(pp);
}
