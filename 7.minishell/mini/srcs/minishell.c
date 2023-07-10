#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *str;
    t_list *list = NULL;
    t_token *token;
    
    str = ft_strdup("ls -al < a | grep  """);
    list = lexer(list, str);
    t_list *cur = list;
    while (cur)
    {
        printf("cur : %d, %s\n", cur->token->type, cur->token->str);
        cur = cur->next;
    }    
}