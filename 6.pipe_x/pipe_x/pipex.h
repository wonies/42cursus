#ifndef PIPE_X_H
# define PIPE_X_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include<sys/wait.h>


typedef struct s_pid
{
    pid_t   pid;
    int     fd[2];
}				t_pid;

typedef struct s_pipe
{
	char    *path;
    char    **str;
    char    **cmd;
    char    *fd_path;
    //child process
    pid_t   pid;
    pid_t   *com;
    //fork
    int     child;
    int     pipe_fd[2];
    //child
    //file
    int     infile;
    int     outfile;
}				t_pipe;

/* path.c */
char    *find_path(char **envp);
// char    **make_slash(char **split);
// int isok_access(char **split, char *ord);
void    isok_access(t_pipe *pp);
void    make_slash(char **split);
void    function_path(int ac, char **av, char **env, t_pipe *pp);
/* ft_split.c */
char	**ft_split(char const *s, char c);

/* init.c */
int     ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
/* init2.c */
char	*ft_strjoin(char const *s1, char const *s2);

#endif