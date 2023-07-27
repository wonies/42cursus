#include "../includes/minishell.h"

void	check_dsign(t_data *data, t_token **token, int *i)
{
	t_token *prev;
	char	*var;
	int`	var_len;

	prev = NULL;
	var = ft_strdup("");
	if (!var)
		return ;
	var_len = 0;
	++(*i);
	if (check_heredoc(data, token, i))
		return ;
	if (check_space(data, token, i))
		return ;
	while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] == '\'' \
		&& data->input[*i] != '\"' && (special_character(data->input[*i]) == 0))
	{
		var_len++;
		var = ft_strncat(var, &data->input[*i++], 1);
	}

}

int	special_character(char c)
{
	if (c == '~' || c == '@' || c == '#' || c == '%' || c == '$' || c == '^' \
	|| c == '&' || c == '*' || c == '(' || c == ')' || c == '=' || c == '+' \
	|| c == '{' || c == '}' || c == '/')
		return 1;
	else
		return 0;
}