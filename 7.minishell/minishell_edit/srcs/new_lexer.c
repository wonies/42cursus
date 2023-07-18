#include "../includes/minishell.h"

void	lexer(t_data	*data)
{
	t_token	*token;
	t_list	**list;
	int		i;

	i = -1;
	list = NULL;
	token = new_token();
	while (data->input[++i])
		input_token(data, &token, &i);
	if (*(token)->str)
		token_to_list(&data->tokens, &token, 0);
}

void	input_token(t_data *data, t_token **token, int *i)
{
	printf("check idx : %c\n", data->input[*i]);
	int flag = 0;

	if (data->input[*i] == '<' || data->input[*i] == '>' || data->input[*i] == '|')
	{
		if (*(*token)->str)
			token_to_list(&data->tokens, token, 1);
		tokenization(data, token, i);
		// printf("check seg : %d\n", data->tokens->pre->token->type);
	}
	else if (data->input[*i] == ' ' || data->input[*i] == '\t')
	{
		if (*(*token)->str)
		{
			token_to_list(&data->tokens, token, 1);
			flag = 1;
		}
	}
	else if (data->input[*i] == '\'' || data->input[*i] == '\"')
		tokenization(data, token, i);
	else if	(data->input[*i] == '$')
	{
		check_dollar(data, token, i);
	}
	else
	{
		(*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
		printf("token->str : %s\n", (*token)->str);
	}
}
