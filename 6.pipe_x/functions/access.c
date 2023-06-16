#include "exec.h"

int main()
{
    char *file_name = "notexist.txt";
    char *wonie_name = "wonie2.txt";

    if (access(file_name, F_OK) == 0)
        printf("%s의 파일이 있습니다.\n", file_name);
    else
        printf("%s의 파일은 존재하지 않습니다.\n", file_name);
    
    if (access(wonie_name, F_OK) == 0)
        printf("%s의 파일이 있습니다.\n", wonie_name);
    else
        printf("%s의 파일은 존재하지 않습니다.\n", wonie_name);
    
}