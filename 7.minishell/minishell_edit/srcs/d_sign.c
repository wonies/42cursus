#include "../includes/minishell.h"

void	check_d_sign(t_data *data, t_token **token, int *i)
{
	if (check_heredoc(data, token, i))
		return ;
	if (check_space(data, token, i))
		return ;
}