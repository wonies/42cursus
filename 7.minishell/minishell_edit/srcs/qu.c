#include "../includes/minishell.h"

// void	double_quote(t_data *data, t_token **token, int *i)
// {
// 	(*i++);
// 	int		start;
// 	int		end;
// 	char	*d_var;
// 	int		check;

// 	start = *i;
// 	end = find_closing_quote(start, data->input, '\"');
// 	d_var = ft_strdup("");
// 	if (!d_var)
// 		return ;
// 	if (data->input[*i] == '$')
// 	{
// 		check = quote_dvar(data, token, i, d_var);
// 		if (!check)
// 			return ;
// 	}
// 	if (end >= 0)
		
		
// }


void    double_quotes(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int start = *i;
    int end = find_closing_quote(start, data->input, '\"') - 1;
    char    *temp;
    printf("end size: %d\n", end);
    temp = ft_strdup("");
    char    *prove_env;
    int len = 0;

    prove_env = NULL;
    if (end >= 0)
    {
		if (!(*(*token)->str))
			(*token) = new_token();
        if (end == 0)
		{
			(*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
			return ;
		}
		else if (end % 2 != 0)
		{
			while (end != 0)
			{
				if (data->input[*i] == '\"')
				{
					(*i)++;
					(*token)->str = ft_strncㅁ
				}
			}
		}
		
		printf("1----------\n");
        if (!(*(*token)->str))
            (*token) = new_token();
        printf("2----------\n");
        while (data->input[*i] != '\"')
        {
            printf("3----------\n");
            if (data->input[*i] == '$')
            {
                printf("dollarcheck!!!!!!!!!!\n");
                (*i)++;
                while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                {
                    printf("4-----------\n");
                    temp = ft_strncat(temp, &data->input[(*i)++], 1);
                }
                printf("temp : ---- %s ---- \n", temp);
                // (*i)++;
                prove_env = possible_env_char(data, token, i, temp);
                printf("prove env : %s\n", prove_env);
                if (prove_env != NULL)
                {
                    (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                    printf("token->str : %s\n", (*token)->str);
                    // (*i) += ft_strlen(temp);
                    printf("{%d}\n", *i);
                    printf("[%c]\n", data->input[*i]);
                }
                // else
                //     (*i) -= (len - 1);
            }
            if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                (*i)++;
            (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
            (*i)++;
        }
    }
    else
    {
        (*token)->str = strncat((*token)->str, &data->input[start - 1], strlen(&data->input[start - 1]));
        (*i) = strlen(data->input) + 1;
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
            }
            i++;
        }
        return (len);
    }
    else
    {
        while (input[i] != '\0')
        {
            if (input[i] == quote)
                return (i);
            i++;
        }
    }
	return (-1);
}



int	find_closing_quote(char *input, int i, char quote)
{
	while (input[i] != '\0' || input[i] != quote)
	{
		if (input[i] == '\\')
			i++;
		if (input[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}






bool	check_heredoc(t_data *data, t_token **token, int *i)
{
	if (data->tokens && data->tokens->token->re_type == T_HEREDOC)
	{
		(*token)->str = ft_strncat((*token)->str, "$", 1);
		--(*i);
		return 1;
	}
	return 0;
}

bool	check_space(t_data *data, t_token **token, int *i)
{
	if (data->input[*i] == ' ' || data->input[*i] == '\t')
    {
        while (data->input[*i] == ' ' || data->input[*i] == '\t')
            (*i)++;
        if (data->input[*i] != '\0' || data->input[*i] != '|')
        {
            (*token) = new_token();
            (*token)->str = ft_strncat((*token)->str, "$ ", 2);
            --(*i);
        }
        return 1;
    }
	return 0;
}

void	check_d_sign(t_data *data, t_token **token, int *i)
{
	char	*var;
	int		var_len;

	var = ft_strdup("");
	if (check_heredoc(data, token, i))
		return ;
	if (check_space(data, token, i))
		return ;
	while (data->input[*i] != '\0' && data->input[*i] != ' ' \
		&& data->input[*i] != '\t' && data->input[*i] != '\'' \
		&& data->input[*i] != '\"')
	{
		var_len++;
		var = ft_strncat(var, &data->input[*i++], 1);
	}
	if (possible_env(data, token, i, var))
		not_env(data, i, var, var_len);
}

void	not_env(t_data *data, t_token **token, int *i, char *var)
{
	int	var_len;

	var_len = ft_strlen(var);
	if (!(*(*token)->str))
		(*token) = new_token();
	if (data->input[*i] != ' ' || data->input[*i] != '\t')
	{
		(*token)->str = ft_strncat((*token)->str, "$", 1);
		(*i) -= (var_len + 1);
		return ;
	}
	(*token)->str = ft_strncat((*token)->str, "$ ", 2);
	(*token)->str = ft_strncat((*token)->str, var, var_len);
	printf("(*token)->str : %s\n", (*token)->str);
	printf("var len ::: %d\n", var_len);
	(*i) -= (var_len + 1);
}

// bool	possible_env(t_data *data, t_token **token, int *i, char *var)
// {
// 	char	*temp;

// 	temp - find_envp(data, var);
// 	if (temp != NULL)
// 	{
// 		if ()
// 	}
// }