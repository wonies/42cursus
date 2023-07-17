#include "../includes/minishell.h"


void    token_to_list(t_list **head, t_token **token, int check)
{
    t_list  *new;

    new = ft_lstnew(*token);
    ft_lstadd_back(head, new);
    if (check == 1)
        *token = new_token();
}

void    tokenization(t_data *data, t_token **token, int *i)
{
    if (data->input[*i] == '|')
        (*token)->type = T_PIPE;
    else if (data->input[*i] == '<' || data->input[*i] == '>')
        redirect_check(data, token, i);
    else if (data->input[*i] == '\'')
        single_quotes(data, token, i);
    else if (data->input[*i] == '\"')
        double_quotes(data, token, i);
    token_to_list(&data->tokens, token, 1);
}