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
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pid
{
    pid_t   pid;
    int     pipe_fd[2];
}				t_pid;

typedef struct s_pipe
{
	char    *path;
    char    **str;
    char    **cmd;
    char    *fd_path;
    //child process
    pid_t   pid;
    t_pid   *com;
    //fork
    int     child;
    char    *limiter;
    int     limiter_len;
    //child
    //file
    int     infile;
    int     outfile;
    
}				t_pipe;

/* path.c */
char    *find_path(char **envp);
void    function_path(int ac, char **av, char **env, t_pipe *pp);
void    make_slash(char **str);
void    execute(t_pipe *pp, char **av, t_pid *ppid);
// char    **make_slash(char **split);
// int isok_access(char **split, char *ord);
void    isok_access(t_pipe *pp);
/* ft_split.c */

size_t	count_str(char const *s, char c);
char	**ft_free_split(char **str, int order);
size_t	str_len(char const *s, char c);
char	*put_word(char const *s, char c);
char	**ft_split(char const *s, char c);

/* init.c */
int     ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
/* init2.c */
void    file_init(int ac, char **av, t_pipe *pp);
char	*ft_strjoin(char const *s1, char const *s2);

/* bonus */
/* gnl */
// char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strchr(char *str, int c);
char			*ft_substr(char const *s, int start, int len);
// int				ft_strlen(const char *str);
char			*data_join(char **data, char *buf);
char			*setting_data(char *str);
char			*devide_line(char **data, int idx);
char			*size_is_zero(char **data, int idx);
char			*read_buf(int fd, char **data, char *buf, int size);
char			*get_next_line(int fd);
/* pipe_gnl */
void    read_gnl(t_pipe *pp);
void    fileinit_bonus(int ac, char **av, t_pipe *pp);
#endif