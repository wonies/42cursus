#include "pipex.h"

// void leaks()
// {
// 	system("leaks a.out");
// }

int main(int ac, char **av, char **env)
{
    t_pipe  pp;

    if (ac != 5)
        error_msg("---We must be write 4 arguments by mandatory part---\n");
    // atexit(leaks);
    file_init(ac, av, &pp);
    function_path(av, env, &pp);
    free_all(&pp);
    return 0;
}
