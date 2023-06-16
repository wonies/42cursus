#include "exec.h"


char * abc[] = {"/bin/ls", "-l", NULL};

int main(int ac, char **agrv,char **env)
{
    printf("execute ls-1!!\n");
    execve(abc[0], abc, NULL);
    perror("execve is failed??");
    exit(1);
}