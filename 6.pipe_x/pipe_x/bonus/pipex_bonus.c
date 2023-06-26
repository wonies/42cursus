#include "../pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipe  pp;

    if (strncmp(av[1], "here_doc", 9) == 0)
    {
        pp.check = 114;
        fileinit_bonus(ac, av, &pp);
        read_gnl(&pp);
    }
    else
        file_init(ac, av, &pp);
    function_path(av, env, &pp);
    free_all(&pp);
    return 0;
}
