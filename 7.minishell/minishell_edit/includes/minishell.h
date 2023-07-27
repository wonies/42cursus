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

# define E_SYNTAX_PIPE "bash: syntax error near unexpected token `|'"
# define E_SYNTAX_INPUT "bash: syntax error near unexpected token `<'"
# define E_SYNTAX_OUTPUT "bash: syntax error near unexpected token `>'"
# define E_SYNTAX_HEREDOC "bash: syntax error near unexpected token `<<'"
# define E_SYNTAX_APPEND "bash: syntax error near unexpected token `>>'"
# define E_SYNTAX_NEWLINE "bash: syntax error near unexpected token `newline'"


typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;


enum    e_type
{
    T_WORD,
    T_PIPE,
    T_CMD,
    T_ARG,
    T_REDIRECT,
    T_INPUT,
	T_OUTPUT,
	T_HEREDOC,
	T_APPEND,
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


typedef struct s_leaf
{
	struct s_leaf	*parent;
	struct s_leaf	*left_child;
	struct s_leaf	*right_child;
	int				leaf_type;
	t_token			*token;
	t_bool			exist;
}t_leaf;


typedef struct s_data
{
	char		*input;
	t_list		*tokens;
	t_list		*envs;
    t_leaf      *root;
    // struct  s_data *next;
}	t_data;



// typedef struct s_treeNode
// {
//     struct s_treeNode *parent;
//     struct s_treeNode *left_child;
//     struct s_treeNode *right_child;
//     int is_pipe;
//     int				leaf_type;
// } TreeNode;


/*ft.c*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *dest, char *src, int n);
t_list	*ft_lst_new(void *content);
char    *ft_strtok(char *str, const char *delim);
// t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const	char *str);
void	*ft_memset(void *b, int c, size_t len);
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstnews();
t_data *new_data();
void    get_envp(t_data *data);
void	env_init(t_data *data, char **env);
void del_envp(t_data *data, char *key);
char    *find_envp(t_data *data, char *key);

t_list *ft_lstnew(t_token *token);
t_token *new_token();
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/* minishell.c*/
// t_token     *new_token();
void    addttlist(t_list **head, t_token *token);

/* lexer.c */
void    check_dollar(t_data *data, t_token **token, int *i);
void    lexer(t_data *data);
void    input_token(t_data *data, t_token **token, int *i);
void    token_to_list(t_list **head, t_token **token, int check);
void    redirect_check(t_data *data, t_token **token, int *i);
void    tokenization(t_data *data, t_token **token, int *i);
bool    possible_env(t_data *data, t_token **token, int *i, char *var);

int find_closing_quote(int i, char *str, char quote);
char *extract_quoted_string(char *str, int start, int end);
void remove_escape_characters(char *str);
int is_quote_character(char c);
/* quote.c */
int    double_quotes(t_data *data, t_token **token, int *i, int ch);
void    single_quotes(t_data *data, t_token **token, int *i, int ch);
int     find_quote(int i, char *str, char quote);
void	env_init(t_data *data, char **env);

/* syntax */
void	syntax(t_data *data);
void	syntax_cmd(t_list	*cur);
void	syntax_arg(t_list	*cur);
void	syntax_redirect(t_list	*cur);
void	syntax_pipe(t_list	*cur);

/* tree.c */
t_leaf	*create_leaf(int leaf_type, t_leaf *parent);
void	init_leaf(t_data *data);
// void print_tree(t_leaf *root, int level, int is_left);
void	tree_leaf(t_leaf **cur_leaf);
void	tree_left_right(t_leaf *cur_leaf, t_list *cur_token);
t_bool	tree_add_left(t_leaf *parent, t_token *new_token, int leaf_type);
t_bool	tree_add_right(t_leaf *parent, t_token *new_token, int leaf_type);
// t_leaf *tree_leaf(t_leaf **cur_leaf);
void print_treess(t_leaf *root);
void print_tree_recursive(t_leaf *node, int level);
char    *possible_env_char(t_data *data, t_token **token, int *i, char *var);
/* recursion */
void	create_pipe(t_leaf **cur);
t_leaf *leaf_create(int leaf_type, t_leaf *parent);
// void	leaf_init(t_data *data);
t_leaf *build_tree(t_list **cur_token);
t_leaf 	*leaf_init(t_data *data);
void print_tree_recursive(t_leaf *node, int level);
void print_tree(t_leaf *root);
void prints_tree(t_leaf *root, int level, int is_left);

bool	check_heredoc(t_data *data, t_token **token, int *i);
bool	check_space(t_data *data, t_token **token, int *i);
void check_dollar(t_data *data, t_token **token, int *i);

/* err.c */
void	syntax_err(char *msg);
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
// void build_tree(t_data *data, TreeNode **root);
// void printf_tree(TreeNode *root, int level, int is_left);

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);

#endif 