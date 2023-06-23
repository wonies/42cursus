#include "pipex.h"

void    execute(t_pipe *pp, char **av, t_pid *ppid)
{
    int i;

    i = 0;
    while (i < pp->child)
    {
        if (i < pp->child - 1)
        {
            if (pipe(pp->com[i].pipe_fd) < 0)
                exit(1);
        }
        if ((pp->com[i].pid = fork()) < 0)
            exit(1);
        if (pp->com[i].pid == 0)
        {
            // close(pp->pipe_fd[0]);
            // close(pp->pipe_fd[1]);
            if (i == 0)
            {
                close(pp->com[i].pipe_fd[0]);
                dup2(pp->com[i].pipe_fd[1],STDOUT_FILENO);
                dup2(pp->infile, STDIN_FILENO);
            }
            else if (i == pp->child - 1)
            {
                dup2(pp->com[i - 1].pipe_fd[0],STDIN_FILENO);
                dup2(pp->outfile, STDOUT_FILENO);
            }
            else
            {
                close(pp->com[i].pipe_fd[0]);
                dup2(pp->com[i - 1].pipe_fd[0],STDIN_FILENO);
                dup2(pp->com[i].pipe_fd[1], STDOUT_FILENO);
            }
            pp->cmd = ft_split(av[i + 2], ' ');
            isok_access(pp);
            if (execve(pp->fd_path, pp->cmd, NULL) < 0)
                exit(1);
        }
        //close(ppid->pipe_fd[0]);
        if (i == 0)
            close(pp->com[i].pipe_fd[1]);
        else if (i == pp->child -1)
            close(pp->com[i - 1].pipe_fd[0]);
        else
        {
            close(pp->com[i - 1].pipe_fd[0]);
            close(pp->com[i].pipe_fd[1]);
        } 
        waitpid(pp->com[i].pid, 0, 0);
        i++;
    }
}

void isok_access(t_pipe *pp)
{
    int     i;
    char    *temp;

    i = 0;
    temp = NULL;
    while (pp->str[i])
    {
        temp = ft_strjoin(pp->str[i], pp->cmd[0]);
        if (access(temp, X_OK) == 0)
        {
            pp->fd_path = temp;
            break ;
        }
        i++;
    }
}

void    make_slash(char **str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_strjoin(str[i], "/");
        i++;
    }
}

char   *find_path(char **env)
{
    char    *path;

    while (*env)
    {
        if (ft_strncmp(*env, "PATH=", 5)==0)
        {
            path = *env + 5;
            break ;
        }
        env++;
    }
    return path;
}

void    function_path(int ac, char **av, char **env, t_pipe *pp)
{
    t_pid   ppid;

    pp->path = find_path(env);
    pp->str = ft_split(pp->path, ':');
    make_slash(pp->str);
    execute(pp, av, &ppid);
}