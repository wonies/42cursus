#include "exec.h"

int main()
{
    FILE *pfile;
    pfile = fopen("notexist", "r");
    if (pfile == NULL)
        printf("Error exist due to notexist file -_-; : %s\n", strerror(errno));
    return 0;
}