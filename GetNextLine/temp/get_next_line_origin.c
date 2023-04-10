// #include "get_next_line.h"

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 100
// #endif

// char *save_data(int idx, char *data, char *temp, int len)
// {
//     len = strlen(data);
//     temp = 
// }

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char *devide_line(char **data)
{
    char *line;
    char *tmp;
    int idx;

    tmp = *data;
    idx = ft_strchr(*data, '\n');
    line = ft_substr(*data, 0, idx + 1);
    *data = ft_substr(*data, idx + 1, ft_strlen(*data));
    free(tmp);
    return line;
}

char    *size_is_zero(char **data)
{
    char *line;
    
    line = ft_substr(*data, 0, ft_strlen(*data));
    if (ft_strlen(*data) <= 0)
    {
        // free(*data);
        // *data = NULL;
        free(line);
        line = NULL;
    }

        free(*data);
        *data = NULL;
    return line;
}

char *read_buf(int fd, char **data, char *buf, int size)
{
    char *temp;
 
    temp = 0;
    while (size)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == -1)
            return NULL;
        buf[size] = '\0';
        if (*data == NULL)
            *data = ft_strdup("");
        if (size == 0)
            return size_is_zero(*&data);
        temp = *data;
        *data = ft_strjoin(*data, buf);
        free(temp);
        temp = NULL;
        if (ft_strchr(*data, '\n') != -1)
            return devide_line(*&data);
    }
    return temp;
}


char *get_next_line(int fd)
{  
    char    *buf;
    static char *data;
    char *temp;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
    {
        free(data);
        data = NULL;
        return (NULL);
    }
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    temp = read_buf(fd, &data, buf, 1);
    free(buf);
    buf = NULL;
    // if (temp != NULL && *temp == '\0')
    // {    
    //     // free(data);
    //     free(temp);
    //     temp = NULL;
    // }
    return temp;
}



// int main(void)
// {
//     int fd;
//     char *str1;
//     char *str2;
//     char *str3;


//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     // while (n>0)
//     // {
//         str1= get_next_line(fd);
//         // str2= get_next_line(fd);
//         // str3= get_next_line(fd);
//         printf("%s",str1);
//         // printf("%s",str2);
//         // printf("%s",str3);
//         // n--;
// //    system("leaks a.out");
//     // }
//     return 0;
// }