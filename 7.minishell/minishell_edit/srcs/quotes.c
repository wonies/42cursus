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
	flag = 1;
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