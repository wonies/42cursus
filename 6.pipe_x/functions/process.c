#include "exec.h"

int main()
{
    pid_t pid1;
    pid_t pid2;
    pid1 = fork();
    while (pid1)
    {
        if (pid1 < 0)
        {
            printf("fork failed\n");
            break ;
        }
        else if (pid1 > 0)
        {
            execl("/bin/ls", "ls", "-1", (char *)0);
            printf("exec failed\n");
        }
        else if (pid1 == 0)
        {
            wait((int *)0);
            printf("ls completed\n");
            exit(0);
        }
    }
}