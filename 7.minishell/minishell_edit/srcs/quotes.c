#include "../includes/minishell.h"

void	double_quote(t_data *data, t_token **token, int *i, int ch)
{
	(*i)++;
	int	end = find_closing_quote(*i, data->input, '\"');
	char	*temp;
	char	*prove_env;
	int		flag;

	temp = ft_strdup("");
	prove_env = NULL;
	flag = 0;
	if ((*(*token)->str) && ch == 0)
        token_to_list(&data->tokens, token, 1);
	if (end == 0)
	{
		(*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
		return ;
	}
	else if (end % 2 == 0)
	{
		printf("----double quote is EVEN----\n");
		while (data->input[*i] != '\"')
		{
			if (data->input[*i] == '$')
			{
				++(*i);
				printf("----%c---\n", data->input[*i]);
				while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
				{
					if (ft_isalnum(data->input[*i]) == 0)
					{
						--(*i);
						break ;
					}
					temp = ft_strncat(temp, &data->input[(*i)++], 1);
				}
				prove_env = possible_env_char(data, token, i, temp);
				printf("--PROVE--ENV-- : %s\n", prove_env);
				if (prove_env)
					(*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
				else
				{
					(*i) -= ft_strlen(temp) + 1;
					if (data->input[*i] != ' ' || data->input[*i] != '\t')
						(*token)->str = ft_strncat((*token)->str, "$", 1);
				}
		}
		if ((data->input[*i] == '\\' && data->input[(*i) + 1] == '\"') || data->input[*i] == '\\' && data->input[(*i) + 1] == '\\')
			(*i)++;
		if (data->input[*i] != '\"')
			(*token)->str = ft_strncata((*token)->str, &data->input[(*i)++], 1);
		if (data->input[*(i + 1)] == '\"')
			flag = 1;
		}
		if (flag == 0 && (data->input[*i] == '\"' && data->input[(*i + 1)] == '\"'))
		{
			(*i)++;
			token_to_list(&data->tokens, token, 0);
		}
	}
	else if (end % 2 != 0)
	{
		while (data->input[*i] != '\"')
		{
			if (data->input[*i] == '$')
			{
				(*i)++;
				while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
				{
					if ((ft_isalnum(data->input[*i])) == 1)
					{
						--(*i);
						break ;
					}
					temp = ft_strncat(temp, &data->input[(*i)++], 1);
				}
				prove_env = possible_env_char(data, token, i, temp);
				if (prove_env)
				{
					(*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
					(*i)++;
				}
				else
				{
					(*i) -= ft_strlen(temp);
					if (data->input[*i] == ' ' || data->input[*i] == '\t')
						(*token)->str = ft_strncat((*token)->str, "$", 1);
				}
			}
			if ((data->input[*i] == '\\' && data->input[(*i) + 1] == '\"') || data->input[*i] == '\\' && data->input[(*i) + 1] == '\\')
				(*i)++;
			(*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
		}
	}
}



void	db_q(t_data *data, t_token **token, int *i, int ch)
{
	++(*i);
	int	end;

	end = find_closing_quote(*i, data->input, '\"');
	if ((*(*token)->str) && ch == 0)
        token_to_list(&data->tokens, token, 1);
	if (end == 0)
	{
		(*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
		return ;
	}
	else if (end % 2 == 0)
		even_quote(data, token, i, '\"');
	else if (end % 2 != 0)
		odd_quote(data, token, i);
}

void	quote_dsign(t_data *data, t_token **token, int *i)
{
	char	*temp;
	char	*prove_env;
	
	++(*i);
	prove_env = NULL;
	temp = ft_strdup("");
	while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
	{
		if (ft_isalnum(data->input[*i]) == 0)
			break ;
		temp = ft_strncat(temp, &data->input[(*i)++], 1);
	}
	prove_env = possible_env_char(data, token, i, temp);
	if (prove_env)
		(*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
	else
		(*i) -= ft_strlen(temp) + 1;
}

void	even_quote(t_data *data, t_token **token, int *i, char quote)
{
	int	quote_flag;
	
	quote_flag = 0;
	while (data->input[*i] != quote)
	{
		if (data->input[*i] == '$' && quote == '\"')
			quote_dsign(data, token, i);
		if ((data->input[*i] == '\\' && data->input[(*i) + 1] == quote) || data->input[*i] == '\\' && data->input[(*i) + 1] == '\\')
			(*i)++;
		if (data->input[*i] != quote)
			(*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
		if (data->input[*(i + 1)] == quote)
			quote_flag = 1;
	}
	if (quote_flag == 0 && (data->input[*i] == quote && data->input[(*i + 1)] == quote))
	{
		(*i)++;
		token_to_list(&data->tokens, token, 0);
	}
}

void	odd_quote(t_data *data, t_token **token, int *i)
{
	while (data->input[*i] != '\"')
	{
		if (data->input[*i] == '$')
			quote_dsign(data, token, i);
		if ((data->input[*i] == '\\' && data->input[(*i) + 1] == '\"') || data->input[*i] == '\\' && data->input[(*i) + 1] == '\\')
				(*i)++;
		(*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
	}
}

void	s_q(t_data *data, t_token **token, int *i, int ch)
{
	int	end;
	int	quote_flag;

	++(*i);
	end = find_closing_quote(*i, data->input, '\'');
	quote_flag = 0;
	if ((*(*token)->str) && ch == 0)
        token_to_list(&data->tokens, token, 1);
    if (end == 0)
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
        return ;
    }
	else if (end % 2 == 0)
		even_quote(data, token, i, '\'');
	else if (end % 2 != 0)
	{
		while (data->input[*i] != '\'')
			(*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
	}
}

int	find_closing_quote(int i, char *line, char quote)
{
	int	cnt;

	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == quote)
			++cnt;
		++i;
	}
	if (cnt == 0)
		return (0);
	else
		return (cnt + 1);
	return (-1);
}