/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:34 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 16:39:34 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

# define HEREDOC "6C413A8D-AA00-4130-B8FA-83E7376ECFD4"

typedef struct s_pid
{
	pid_t	pid;
	int		pipe_fd[2];
}				t_pid;

typedef struct s_pipe
{
	char	*path;
	char	**str;
	char	**cmd;
	char	*fd_path;
	t_pid	*com;
	int		child;
	char	*limiter;
	int		limiter_len;
	int		infile;
	int		outfile;
	char	**env;
	int		check;
}				t_pipe;

/* path_parsing.c */
void	function_path(char **av, char **env, t_pipe *pp);
char	*find_path(char **envp);
void	make_slash(t_pipe *pp);
void	isok_access(t_pipe *pp);

/* path_process.c */
void	execute(t_pipe *pp, char **av);
void	cmd_split(int i, t_pipe *pp, char **av);
void	wait_child(t_pipe *pp);
void	child_exe(int i, t_pipe *pp, char **av);
void	close_fd(int i, t_pipe *pp);

/* path_process_transp */
void	process_transp(int i, t_pipe *pp);
void	process_transp_the_one(int zero, t_pipe *pp);
void	process_check_zero(int i, t_pipe *pp);

/* split.c */
size_t	count_str(char const *s, char c);
char	**ft_free_split(char **str, int order);
size_t	str_len(char const *s, char c);
char	*put_word(char const *s, char c);
char	**ft_split(char const *s, char c);

/* init.c */
int		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* init_file.c */
char	*ft_strjoin(char const *s1, char const *s2s);
void	file_init(int ac, char **av, t_pipe *pp);
void	pp_setting(int ac, t_pipe *pp);

/* freecloseerror*/
void	error_msg(char *msg);
void	free_all(t_pipe *pp);
void	close_all(t_pipe *pp);
void	infile_errmsg(t_pipe *pp, char **av);

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
void	read_gnl(t_pipe *pp);
void	fileinit_bonus(int ac, char **av, t_pipe *pp);

#endif
