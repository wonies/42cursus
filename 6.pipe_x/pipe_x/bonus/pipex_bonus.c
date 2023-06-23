#include "../pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipe  pp;

    if (strncmp(av[1], "here_doc", 9) == 0)
        fileinit_bonus(ac, av, &pp);
    else
        file_init(ac, av, &pp);
    read_gnl(&pp);
    function_path(ac, av, env, &pp);
}