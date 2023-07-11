#include "../includes/minishell.h"

void    double_quotes(t_list **list, t_token **token, char *str, int *idx)
{
    // t_list *head;
    // t_token *token;
    int     len;

    len = ft_strlen(str);
    while (str[++(*idx)])
    {
        // *token = new_token();
        if (!(*token)->str)
                (*token)->str = ft_strdup("");
        (*token)->str = ft_strncat((*token)->str, &str[*idx], 1); 
        if (str[(*idx)] == '"')
        {
            addttlist(list, *token);
            break ;
        }
    }
}

void    single_quotes(t_list **list, t_token **token, char *str, int *idx)
{
    int     len;

    len = ft_strlen(str);
    while (str[++(*idx)])
    {
        // *token = new_token();
        if (!(*token)->str)
                (*token)->str = ft_strdup("");
        (*token)->str = ft_strncat((*token)->str, &str[*idx], 1); 
        if (str[(*idx)] == '\'')
        {
            addttlist(list, *token);
            break ;
        }
    }
}