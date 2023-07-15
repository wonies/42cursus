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

#define BUFFER_SIZE 1024
#define DELIMS " \t\r\n"
#define READ 0
#define WRITE 1
#define ERROR -1

enum    e_type
{
    T_WORD,
    T_PIPE,
    T_REDIRECT,
    T_INPUT,
	T_OUTPUT,
	T_HEREDOC,
	T_APPEND,
    T_DOUBLE_Q,
    T_SINGLE_Q,
    T_SPACE // 추후에 고려해보기
};

typedef struct  s_token
{
    int     type;
    int     re_type;
    char    *str;
}   t_token; 


typedef struct s_list
{
    struct  s_list *next;
	struct  s_list *pre;
    t_token *token;
    // void    *content;
    char    *env;
}				t_list;


typedef struct s_mini
{
	int     infile;
    int     outfile;
    char    **env;
    
}				t_mini;

typedef struct s_data
{
	char		*input;
	t_list		*tokens;
	t_list		*envs;
    // struct  s_data *next;
}	t_data;


/*ft.c*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *dest, char *src, int n);
t_list	*ft_lst_new(void *content);
// t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const	char *str);
void	*ft_memset(void *b, int c, size_t len);
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstnews();
t_data *new_data();
void    get_envp(t_data *data);
void	env_init(t_data *data, char **env);
void del_envp(t_data *data, char *key);
t_list    *find_envp(t_data *data, char *key);


t_token *new_token();
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/* minishell.c*/
// t_token     *new_token();
void    addttlist(t_list **head, t_token *token);

/* lexer.c */

void    *lexer(t_data *data);
void    input_token(t_data *data, t_token **token, int *i);
void    token_to_list(t_list **head, t_token **token, int check);
void    redirect_check(t_data *data, t_token *token, int *i);
void    tokenization(t_data *data, t_token **token, int *i);




/* quote.c */
void    double_quotes(t_data *data, t_token **token, int *i);
void    single_quotes(t_data *data, t_token **token, int *i);
bool    find_quote(int i, char *str, char quote);
void	env_init(t_data *data, char **env);
/* bonus */
/* gnl */
int		ft_strchr(char *str, int c);
// char	*ft_substr(char const *s, int start, int len);
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