#include "exec.h"

int main()
{
    pid_t pid;
    
    printf("Before the fork\n");
    pid = fork();
    
    if(pid == 0)
        printf("this is the child pid = ||%d||\n%d\n%p\n", pid, getpid(), (void*)&pid);
    else if (pid > 0)
        printf("this is the parent pid = ||%d||\n%d\n%p\n", pid, getpid(), (void*)&pid);
    else
        printf("fork is failed!!\n");
}