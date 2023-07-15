#include "../includes/minishell.h"

void    double_quotes(t_data *data, t_token **token, int *i)
{
    if (find_quote(*i, data->input, '\"') == 1)
    {    
        (*token)->str = ft_strncat((*token)->str, "\"", 1);
        (*i)++;
        return ;
    }
    while (data->input[++(*i)])
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1); 
    }
}

void    single_quotes(t_data *data, t_token **token, int *i)
{

    if (find_quote(*i, data->input, '\'') == 1)
    {    
        (*token)->str = ft_strncat((*token)->str, "\'", 1);
        (*i)++;
        return ;
    }
    while (data->input[++(*i)])
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
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