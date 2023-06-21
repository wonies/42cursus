#include "pipex.h"


void    file_init(int ac, char **av, t_pipe *pp)
{
    pp->infile = open(av[1], O_RDONLY);
    if (pp->infile < 0) 
    {
        perror("Failed to open input file\n");
        exit(1);
    }
    pp->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (pp->outfile < 0)
    {
        perror("Failed to open out file\n");
        exit(1);
    }
    pp->child = ac - 3;
    pp->com = (t_pipe *)ft_calloc(pp->child, sizeof(t_pipe));
}


int main(int ac, char **av, char **envp)
{
    t_pipe  pp;

    // pp.child = ac - 3;
    // printf("pp.child : %d\n", pp.child);
    file_init(ac, av, &pp);
    function_path(ac, av, envp, &pp);
    printf("2 pp.child : %d\n", pp.child);
    
    // if (pipe(pp.pipe_a) < 0)
    //     exit(1);
    // if ((pp.pid1=fork() < 0) || (pp.pid2=fork() < 0))
    //     exit(1);
    // if (pp.pid1 > 0 && pp.pid2 > 0)
    //     printf("%d", pp.pid1);
    // else if (pp.pid1 == 0)
    // {

    // }
    // else if (pp.pid2 == 0)
    // {
    //     read(pp.pipe_a[0], pp.cmd[0], 4);
    // }
    // pp.path = find_path(envp);
    // pp.str = ft_split(pp.path, ':');
    // pp.child = ac - 3;
    // make_slash(pp.str);
    // // execute(&pp);
    // pp.cmd = ft_split(av[2], ' ');
    // isok_access(pp.str, pp.cmd[0]);
    // printf("cmd : %s\n", pp.cmd[0]);
    // pp.cmd = ft_split(av[3], ' ');
    // printf("cmd : %s\n", pp.cmd[0]);
    // isok_access(pp.str, pp.cmd[0]);

    return 0;
}

// void    change_str(char **str)
// {
//     // int i = 0;
//     // while (str[i])
//     // {
//     *str = "wondi";
//     //     i++;
//     // }
// }

// int main()
// {
//     // char **str;

//     // str[0] = "wonie";
//     // str[1] = "hi";
//     // str[2] = NULL;
//     char *str;

//     str = "wonie";
//     change_str(&str);
//     // int i = 0;
//     // while (i < 3)
//     printf("%s\n", str);
// }