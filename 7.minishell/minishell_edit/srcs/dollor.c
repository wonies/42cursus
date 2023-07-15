#include "../includes/minishell.h"

void    env_dollor(t_data *data, t_token *token, int *i)
{
    char    *var;

    (*i)++;
    while (data->input[*i] == ' ' || data->input[*i] == '\t')
    {
        token->str = ft_strncat(token->str, "$", 1);
        return ;
    }
}