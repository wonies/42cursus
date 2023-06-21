// #include "pipex.h"

// void    execute(t_pipe *pp, char **av)
// {
//     int i;

//     i = 0;
//     if (pipe(pp->pipe_fd) < 0)
//         exit(1);
//     while (i < pp->child)
//     {
//         if ((pp->com[i] = fork()) < 0)
//             exit(1);
//         if (pp->com[i] > 0)
//         {
//             close(pp->pipe_fd[0]);
//             close(pp->pipe_fd[1]);
//             waitpid(pp->com[i], NULL, WNOHANG);
//         }
//         if (pp->com[i] == 0)
//         {
//             pp->infile = open(av[1], O_RDONLY);
//             if (pp->infile < 0) 
//             {
//                 perror("Failed to open input file");
//                 exit(1);
//             }
//             // close(pp->pipe_fd[0]);
//             // close(pp->pipe_fd[1]);
//             if (i == 0)
//             {
//                 dup2(pp->infile, STDIN_FILENO);
//                 dup2(pp->pipe_fd[0],STDIN_FILENO);
//                 close(pp->pipe_fd[0]);
//             }
//             if (i == pp->child - 1)
//             {
//                 dup2(i + 2, STDOUT_FILENO);
//                 dup2(pp->pipe_fd[1],STDOUT_FILENO);
//                 close(pp->pipe_fd[1]);
//             }
//             pp->cmd = ft_split(av[i + 2], ' ');
//             isok_access(pp);
//             if (execve(pp->fd_path, pp->cmd, NULL) < 0)
//                 exit(1);
//         }
//         // pp->cmd = ft_split(av[i + 2], ' ');
//         // printf("av : %s\n", av[i+2]);
//         // isok_access(pp); //execve 실행하니까 명령어가 ls , cat인데 cat이 실행이 안됨 
//         // execve(pp->fd_path, pp->cmd, NULL);
//         // perror("command not found\n");
//         // dup2(pp->pipe_fd[1], 1);

//         i++;
//     }
// }

// void isok_access(t_pipe *pp)
// {
//     int     i;
//     char    *temp;

//     i = 0;
//     temp = NULL;
//     while (pp->str[i])
//     {
//         temp = ft_strjoin(pp->str[i], pp->cmd[0]);
//         if (access(temp, X_OK) == 0)
//         {
//             pp->fd_path = temp;
//             break ;
//         }
//         i++;
//     }
// }

// void    make_slash(char **str)
// {
//     int     i;

//     i = 0;
//     while (str[i])
//     {
//         str[i] = ft_strjoin(str[i], "/");
//         i++;
//     }
// }


// // char   **make_slash(char **split)
// // {
// //     int     i;

// //     i = 0;
// //     while (split[i])
// //     {
// //         split[i] = ft_strjoin(split[i], "/");
// //         i++;
// //     }
// //     return split;
// // }

// char   *find_path(char **env)
// {
//     char    *path;

//     while (*env)
//     {
//         if (ft_strncmp(*env, "PATH=", 5)==0)
//         {
//             path = *env + 5;
//             break ;
//         }
//         env++;
//     }
//     return path;
// }

// void    function_path(int ac, char **av, char **env, t_pipe *pp)
// {
//     pp->path = find_path(env);
//     pp->str = ft_split(pp->path, ':');
//     pp->child = ac - 3;
//     make_slash(pp->str);
//     // int i = 0;
//     // while (pp->str[i])
//     //     printf("after slash : %s\n", pp->str[i++]);
//     execute(pp, av);
// }