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
# define BUFFER_SIZE 42
#endif

// int times;

// char *devide_line(char **data)
// {
//     char *line;
//     char *tmp;
//     int idx;
    
//     tmp = *data;
//     idx = ft_strchr(*data, '\n');
//     line = ft_substr(*data, 0, idx + 1);
//     *data = ft_substr(*data, idx + 1, ft_strlen(*data));
//     free(tmp);
//     return line;
// }

char *devide_line(char **data)
{
    char *line;
    char *data_new;
    int idx;
    int flag =0;
    
    data_new = 0;
    if(!*data)
    {
        free(*data);
        *data = NULL;
        return(NULL);
    }
    idx = ft_strchr(*data, '\n');
    line = ft_substr(*data, 0, idx + 1);
    if (line)
    {
        data_new = ft_substr(*data, idx + 1, ft_strlen(*data));
        if (!data_new)
            flag = 1;
    }
    else
        line = NULL;
    if (*data)
        free(*data);
    if (flag == 0)
        *data = data_new;
    return line;
}

char    *size_is_zero(char **data)
{
    char *line;
    
    if (ft_strchr(*data, '\n') != -1)
        return devide_line(&*data);
    line = ft_substr(*data, 0, ft_strlen(*data));
    if (!line)
    {
        free(*data);
        *data = NULL;
        return line;
    }
    if (ft_strlen(*data) <= 0 || *line == '\0')
    {
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
 
    temp = NULL;
    while (size)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == -1)
            return NULL;
        buf[size] = '\0';
        if (*data == NULL)
        {
            *data = ft_strdup("");
            if (!*data)
                return (NULL);
        }
        if (size == 0)
            return size_is_zero(*&data);
        temp = *data;
        *data = ft_strjoin(*data, buf);
        free(temp);
        temp = NULL;
        if (*data == NULL)
            return NULL;
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
        if (data)
        {
            free(data);
            data = NULL;
        }
        return (NULL);
    }
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    // buf = (char *)malloc(-1);
    if (buf == NULL)
        return (NULL);
    temp = read_buf(fd, &data, buf, 1);
    // if (temp == NULL)
    // {
    //     if (data)
    //     {
    //         free(data);
    //         data = NULL;
    //     }
    // }
    free(buf);
    buf = NULL;
    return temp;
}



// int main(void)
// {
//     int fd;
//     char *str1;
//     char *str2;
//     char *str3;
//     fd = open("test.txt", O_RDWR);
//     get_next_line(fd);
//     get_next_line(fd);
//     get_next_line(fd);
//     get_next_line(fd);
//     get_next_line(fd);
//     // get_next_line(fd, NULL); 
//     close(fd);

       
   
//     return 0;
// }