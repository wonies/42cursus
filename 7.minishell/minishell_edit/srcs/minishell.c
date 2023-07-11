#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *str;
    t_list *list = NULL;
    
    // str = ft_strdup("ls -al < a | grep  "" | cat -e | head -3 >> outfile");
    // str = ft_strdup("< infile ls | cat > outfile");
    
    str = readline("prompt : ");
    if (str)
        printf("%s\n", str);
    add_history(str);
    list = lexer(list, str);
    t_list *cur = list;
    while (cur)
    {
        printf("cur : %d, %s\n", cur->token->type, cur->token->str);
        cur = cur->next;
    }    
}