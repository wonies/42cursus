#include "../includes/minishell.h"

void	double_quote(t_data *data, t_token **token, int *i)
{
	(*i++);
	int		start;
	int		end;
	char	*d_var;
	int		check;

	start = *i;
	end = find_closing_quote(start, data->input, '\"');
	d_var = ft_strdup("");
	if (!d_var)
		return ;
	if (data->input[*i] == '$')
	{
		check = quote_dvar(data, token, i, d_var);
		if (!check)
			return ;
	}
	if (end >= 0)
		
		
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