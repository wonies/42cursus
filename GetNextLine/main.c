
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *test;

    fd = open("./test1", O_RDONLY);
    test = get_next_line(fd);
    printf("%s", test);
    // printf("address --- %p\n", test);
    test = get_next_line(fd);
    printf("%s", test);
    test = get_next_line(fd);
    printf("%s", test);
    test = get_next_line(fd);
    printf("%s", test);
    test = get_next_line(fd);
    printf("%s", test);
    
    // test = get_next_line(fd);
    // printf("%s:3", test);
    // test = get_next_line(fd);
    // printf("%s:4", test);
    // test = get_next_line(fd);
    // printf("%s:5", test);
    // test = get_next_line(fd);
    // printf("%s", test);


    return (0);
}