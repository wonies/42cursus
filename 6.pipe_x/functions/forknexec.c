#include "exec.h"

char *abc[] = {"/bin/ls", "-l", NULL};

int main(int argc, char **argv, char **env) {
    printf("execute ls-1!!\n");

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork is failed");
        exit(1);
    } else if (pid == 0) {
        // 자식 프로세스
        execve(abc[0], abc, NULL);
        perror("execve is failed");
        exit(1);
    } else {
        // 부모 프로세스
        printf("Parent process is still running\n");
    }
    printf("parents alive\n");
    // 추가적인 부모 프로세스 코드 작성 가능

    return 0;
}
