#include "../pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipe  pp;

    // printf("%s\n", av[1]);
    // printf("%d\n", strncmp(av[1], "here_doc", 9) == 0);
    if (strncmp(av[1], "here_doc", 9) == 0)
    {
        fileinit_bonus(ac, av, &pp);
        read_gnl(&pp);
    }
    else
        file_init(ac, av, &pp);
    printf("%d\n", pp.child);
    function_path(ac, av, env, &pp);
}