#ifndef GNL_H
# define GNL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strchr(char *str, int c);
char    *ft_substr(char const *s, int stasrt, int len);
int     ft_strlen(const char *str);
char	*data_join(char **data, char *buf);
char	*setting_data(char **data);
char    *devide_line(char **data, int idx, int flag);
char    *size_is_zero(char **data, int idx);
char	*read_buf(int fd, char **data, char *buf, int size);
char	*get_next_line(int fd);

#endif