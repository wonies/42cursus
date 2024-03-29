#ifndef MINI_H
#define	MINI_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <string.h>

#define DELIMS " \t\r\n"
#define READ 0
#define WRITE 1
#define T_NULL 0
#define T_WORD 1
#define T_PIPE 2
#define T_READIRECT 3
#define T_DOUBLE_QUOTES 4
#define T_SINGLE_QUOTES 5

typedef struct  s_token
{
    int     type;
    char    *str;
}   t_token;

typedef struct s_pid
{
	pid_t	pid;
	int		pipe_fd[2];
}				t_pid;


typedef struct s_list
{
	struct  s_list *next;
    char    *string;
}				t_list;


typedef struct s_mini
{
	int     infile;
    int     outfile;
    char    **env;
    
}				t_mini;


/* bonus */
/* gnl */
int		ft_strchr(char *str, int c);
char	*ft_substr(char const *s, int start, int len);
char	*data_join(char **data, char *buf);
char	*setting_data(char *str);
char	*devide_line(char **data, int idx);
char	*size_is_zero(char **data, int idx);
char	*read_buf(int fd, char **data, char *buf, int size);
char	*get_next_line(int fd);
/* pipe_bonus */
void	read_gnl(t_mini *pp);
void	fileinit_bonus(int ac, char **av, t_mini *pp);


#endif 