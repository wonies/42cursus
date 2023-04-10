#ifndef GNL_H
# define GNL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int ft_strchr(char *str, int c);
char	*ft_substr(char const *s, int stasrt, int len);
int ft_strlen(const char *str);
char    *get_next_line(int fd);

#endif