#include "pipex.h"

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
            free(temp);
            break ;
        }
        free(temp);
        i++;
    }
}

void    make_slash(t_pipe *pp)
{
    int     i;
    char    *temp;

    i = 0;
    while (pp->str[i])
    {
        temp = ft_strjoin(pp->str[i], "/");
        free(pp->str[i]);
        pp->str[i] = temp;
        i++;
    }
}

char   *find_path(char **env)
{
    char    *path;

    path = NULL;
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

void    function_path(char **av, char **env, t_pipe *pp)
{
    pp->env = env;
    if (!pp->env)
        error_msg("not allocated ENV!\n");
    pp->path = find_path(env);
    if (!pp->path)
        error_msg("not allocated PATH!\n");
    pp->str = ft_split(pp->path, ':');
    if (!pp->str)
        error_msg("not allcoated SPLIT!\n");
    make_slash(pp);
    if (!pp->str)
        error_msg("not allcoated JOIN!\n");
    execute(pp, av);
}
