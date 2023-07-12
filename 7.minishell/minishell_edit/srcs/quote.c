#include "../includes/minishell.h"

void    double_quotes(t_list **list, t_token **token, char *str, int *idx)
{
    if (find_quote(*idx, str, '\"') == 0)
    {    
        if (!(*token)->str)
                (*token)->str = ft_strdup("");
        (*token)->str = ft_strncat((*token)->str, "\"", 1);
        (*idx)++;
        return ;
    }
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

     if (find_quote(*idx, str, '\'') == 0)
    {    
        if (!(*token)->str)
                (*token)->str = ft_strdup("");
        (*token)->str = ft_strncat((*token)->str, "\'", 1);
        (*idx)++;
        return ;
    }
    while (str[++(*idx)])
    {
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

bool    find_quote(int i, char *str, char quote)
{
    while (str[i] == quote || str[i] == '\0')
    {
        if (str[i] == '\\' && str[i++] == quote)
            i++;
        i++;
    }
    printf("%d\n", i);
    if (str[i] == '\0')
        return (0);
    return (1);
}