#include "../../includes/minishell.h"

void	syntax(t_data *data)
{
	t_list	*cur;

	if (!data->tokens)
		return ;
	cur = data->tokens;
	syntax_cmd(cur);
	cur = cur->next;
	while (cur)
	{
		printf("CUR FOUND\n");
		if (cur->token->type == T_WORD)
			syntax_arg(cur);
		else if (cur->token->type == T_PIPE)
			syntax_pipe(cur);
		else if (cur->token->type == T_REDIRECT)
			syntax_redirect(cur);
		cur = cur->next;
	}
}

void	syntax_cmd(t_list	*cur)
{
	if (cur->token->type == T_WORD)
		cur->token->type = T_CMD;
	else if (cur->token->type == T_PIPE)
		syntax_err(E_SYNTAX_PIPE);
}

// void	syntax_arg(t_list	*cur)
// {
// 	printf("seg found\n");
// 	if (cur->pre->pre->token->type == T_REDIRECT && cur->pre->token->type == T_ARG)
// 		cur->token->type = T_CMD; -> pre가 없을 수도 있으므로 seg뜸
// 	else if (cur->pre->token->type == T_CMD || cur->pre->token->type == T_PIPE )
// 		cur->token->type = T_ARG;
// 	else if (cur->pre->token->type == T_PIPE)
// 		cur->token->type = T_CMD;
// 	// if (cur->pre->pre->token->type == T_REDIRECT && (cur->pre->token->type == T_ARG))
// 	// 	cur->token->type = T_CMD;
// 	// else if (cur->pre->token->type == T_CMD || cur->pre->token->type == T_ARG \
// 	// 	|| cur->pre->token->type == T_PIPE || cur->pre->token->type == T_REDIRECT)
// 	// 		cur->token->type = T_ARG;
// 	// else if (cur->pre->token->type == T_PIPE)
// 	// 	cur->token->type = T_CMD;
// 	printf("seg found!!!!!!!!!!!\n");
// }

void syntax_arg(t_list *cur)
{
	if (cur->pre && cur->pre->pre && cur->pre->pre->token->type == T_REDIRECT && (cur->pre->token->type == T_ARG))
		cur->token->type = T_CMD;
	else if (cur->pre && (cur->pre->token->type == T_CMD || cur->pre->token->type == T_ARG || cur->pre->token->type == T_REDIRECT))
		cur->token->type = T_ARG;
	else if (cur->pre && cur->pre->token->type == T_PIPE)
		cur->token->type = T_CMD;
}

void	syntax_redirect(t_list	*cur)
{
	if (cur->pre && cur->pre->token->type == T_REDIRECT)
	{
		if (cur->token->re_type == T_INPUT)
			syntax_err(E_SYNTAX_INPUT);
		else if (cur->token->re_type == T_HEREDOC)
			syntax_err(E_SYNTAX_HEREDOC);
		else if (cur->token->re_type == T_OUTPUT)
			syntax_err(E_SYNTAX_OUTPUT);
		else if (cur->token->re_type == T_APPEND)
			syntax_err(E_SYNTAX_APPEND);
	}
}

void	syntax_pipe(t_list	*cur)
{
	if (cur->pre && cur->pre->token->type == T_PIPE)
		syntax_err(E_SYNTAX_PIPE);
	else if (cur->token->type == T_REDIRECT)
		syntax_err(E_SYNTAX_PIPE);
	else if (!cur->next)
		syntax_err(E_SYNTAX_NEWLINE);
}
