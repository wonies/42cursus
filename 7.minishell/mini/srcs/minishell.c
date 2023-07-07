#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *str;
    t_list *list;

    str = ft_strdup("ls -al < a | grep  """);
    list = lexer(str);
    t_list *cur = list;
    while (cur)
    {
        printf("%s\n", cur->content);
        cur = cur->next;
    }    
}