#include "../includes/minishell.h"


t_token     *new_token()
{
    t_token *token;

    token = (t_token *)ft_calloc(1, sizeof(t_token));
    token->type = T_WORD;
    return token;
}

void    addttlist(t_list **head, t_token *token)
{
    t_list  *new;

    new = ft_lstnew(token);
    if (!new)
        return 0;
    ft_lstadd_back(head, new);
}


void    tokenization(char *str, int *idx, t_list **head, t_token **token)
{

    if (str[*idx] == '|')
    {
        (*token)->type = T_PIPE;
        (*token)->str = ft_strdup("|");
    }
    else if (str[*idx] == '\"')
    {
        (*token)->type = T_DOUBLE_Q;
        (*token)->str = ft_strdup('\"');
        (*token)->double_flag++;
    }
    else if (str[*idx] == '\'')
    {
        (*token)->type = T_SINGLE_Q;
        (*token)->str = ft_strdup('\'');
        (*token)->single_flag++;
    }
    else if (str[*idx] == '>' || str[*idx] == '<')
    {
        (*token)->type = T_REDIRECT;
        if (str[*idx + 1] == str[*idx])
        {
            (*token)->str = ft_strncat((*token)->str, &str[*idx], 2);
            *idx++;
        }
        else
        {
            if (str[*idx] == '<')
                (*token)->str = ft_strdup('<');
            else
                (*token)->str = ft_strdup('>');
        }
    }
    else if (str[*idx] == ' ')
        *idx++;
    addttlist(head, *token);
    *token = new_token();

}


t_list *lexer(t_list *list, char *str)
{
    int i = 0;
    int idx = 0;
    t_token *token;
    t_list *head;

    token = new_token();
    if (!token)
        return (NULL);
    while (str[idx])
    {
        if (str[idx] == '\"' || str[idx] == '\'' || str[idx] == '|' || str[idx] == '<' || str[idx] == '>' || str[idx] == ' ')
        {
            tokenization(str, &idx, &head, &token);
            if (i != idx)
                addttlist(&head, ft_substr(str, i, idx));
            i = idx + 1;
        }
        idx++;
    }
    return (head);
}