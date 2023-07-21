#include "../includes/minishell.h"

void    double_quote(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int end = find_closing_quote(i, data->input, '\"');
    char    *temp;
    char    *prove_env;

    temp = ft_strdup("");
    prove_env = NULL;

    if (!(*(*token)->str))
        (*token) = new_token();
    if (end == 0)
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
        return ;
    }
    else if (end % 2 != 0)
    {
        while (data->input[*i] != '\"')
        {
            if (data->input[*i] == '$')
            {
                (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                    else
                        (*i) -= ft_strlen(temp);
            }
            if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
            (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
        }
    }
    else if (end % 2 == 0)
    {
        if (end > 1)
        {
            while (data->input[*i] != '\"')
            {
                if (data->input[*i] == '$')
                {
                    (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                    else
                        (*i) -= ft_strlen(temp);
                }
                if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
                (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
            }
        }
        else if (end == 0)
        {
             while (data->input[*i] != '\"')
            {
                if (data->input[*i] == '$')
                {
                    (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                    else
                        (*i) -= ft_strlen(temp);
                }
                if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
                 while (data->input[*i] != '\"')
            {
                if (data->input[*i] == '$')
                {
                    (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                    else
                        (*i) -= ft_strlen(temp);
                }
                if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
                (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
            }
            }
            if (data->input[*i] == '\"')
                 (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
        }
    }

}



void    single_quote(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int end = find_closing_quote(*i, data->input, '\'');
    
    int flag = 0;
    if ((*(*token)->str))
        token_to_list(&data->tokens, token, 1);
    if (end == 0)
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
        return ;
    }
    else if (end % 2 == 0)
    {
        while (data->input[*i] != '\'')
        {
            (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
            if (data->input[*(i + 1)] == '\'')
                flag = 1;
        }
        if (flag == 0 && (data->input[*i] == '\'' && data->input[*i + 1] == '\''))
        {
            (*i)++;
            token_to_list(&data->tokens, token, 0);
            return ;
        }
    }
    else if (end % 2 != 0)
    {
        while (data->input[*i] != '\'')
            (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
    }
}






int	find_closing_quote(int i, char *input, char quote)
{
    int len = 0;

    if (quote == '\"')
    {
        while (input[i] != '\0')
        {
            if (input[i] == quote)
            {
                len++;
                printf("len : %d\n", len);
            }
            i++;
        }
        if (len == 0)
            return 0;
        else
            return (len + 1);
    }
    else
    {
        w while (input[i] != '\0')
        {
            if (input[i] == quote)
            {
                len++;
                printf("len : %d\n", len);
            }
            i++;
        }
        if (len == 0)
            return 0;
        else
            return (len + 1);
    }
	return (-1);
}