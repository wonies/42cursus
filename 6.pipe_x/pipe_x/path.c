#include "pipex.h"

void    execute(t_pipe *pp)
{
    int i;

    i = 0;
    if (pipe(pp->pipe_a) < 0)
        exit(1);
    while (i < pp->child)
    {
        if (pp->com[i])
    }
}

void isok_access(char **split, char *ord)
{
    int     i;
    char    *temp;

    i = 0;
    temp = NULL;
    printf("%s\n", ord);
    while (split[i])
    {
        temp = ft_strjoin(split[i], ord);
        if (access(temp, X_OK) == 0)
        {
            printf("me : %s\n", temp);
            break ;
        }
        i++;
    }
}

void    make_slash(char **split)
{
    int     i;

    i = 0;
    while (split[i])
    {
        split[i] = ft_strjoin(split[i], "/");
        i++;
    }
}


// char   **make_slash(char **split)
// {
//     int     i;

//     i = 0;
//     while (split[i])
//     {
//         split[i] = ft_strjoin(split[i], "/");
//         i++;
//     }
//     return split;
// }

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