#include <stdio.h>
#include <stdlib.h>

int main() {
    char *path = getenv("PATH");
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH environment variable not found\n");
    }

    return 0;
}