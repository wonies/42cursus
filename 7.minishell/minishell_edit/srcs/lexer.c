#include "../includes/minishell.h"

t_list *ft_lstnew(t_token *token)
{
    t_list *new = malloc(sizeof(t_list));
    if (new)
    {
        new->next = NULL;
        new->token = token;
    }
    return new;
}

t_token *new_token()
{
	t_token *token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->str = ft_strdup("");
	token->type = T_WORD;
	
	return token;
}


t_data *new_data()
{
    t_data *data;

    data = (t_data *)ft_calloc(1, sizeof(t_data));
    return data;
}

void	addttlist(t_list **head, t_token *token)
{
	t_list *new;

	new = ft_lstnew(token);
	ft_lstadd_back(head, new);
}


void tokenization(char *str, int *idx, t_list **head, t_token **token)
{
    //if (!(*token))
    *token = new_token();
    if (str[*idx] == '|')
    {
        (*token)->type = T_PIPE;
        (*token)->str = "|";
    }
    else if (str[*idx] == '\"')
    {
        if (str[*idx + 1] == str[*idx])
        {
            (*token)->type = T_DOUBLE_Q;
            (*token)->str = "\"\"";
            (*idx)++;
        }
        else
        {
            (*token)->type = T_DOUBLE_Q;
          //  (*token)->double_flag++;
            (*token)->str = "\"";
            addttlist(head, *token);
            *token = new_token();
            double_quotes(head, token, str, idx);
            return ;
        }
    }
    else if (str[*idx] == '\'')
    {
        if (str[*idx + 1] == str[*idx])
        {
            (*token)->type = T_SINGLE_Q;
            (*token)->str = "\'\'";
            (*idx)++;
        }
        else
        {
            (*token)->type = T_SINGLE_Q;
            (*token)->str = "\'";
            addttlist(head, *token);
            *token = new_token();
            single_quotes(head, token, str, idx);
            return ;
        }
    }
    else if (str[*idx] == '>' || str[*idx] == '<')
    {
        (*token)->type = T_REDIRECT;
        if (str[*idx] == '>')
        {
            if (str[*idx + 1] == str[*idx])
            {
                (*token)->str = ">>";
                (*idx)++;
            }
            else
                (*token)->str = ">";
        }
        else
        {
            if (str[*idx + 1] == str[*idx])
            {
                (*token)->str = "<<";
                (*idx)++;
            }
            else
                (*token)->str = "<";
        }
    }
    addttlist(head, *token);
}

t_list *lexer(t_list *list, char *str)
{
	t_list *head;
	t_token *token;
	int	i;

	i = 0;
	head = NULL;
	token = new_token();
	while (str[i])
	{
        if (str[i] == '<' || str[i] == '>' || str[i] == '|' || str[i] == '\"' || str[i] == '\'')
        {
            if (token->str)
                addttlist(&head, token);
            tokenization(str, &i, &head, &token);
            token = new_token();
		}
        else if (str[i] == ' ' || str[i] == '\t')
        {
            if (token->str)
            {
                addttlist(&head, token);
                token = new_token();
            }
        }
		else
        {
            if (!token->str)
                token->str = ft_strdup("");
			token->str = ft_strncat(token->str, &str[i], 1);
            printf("%s\n", token->str);
        }
		i++;
	}
    if (token->str)
        addttlist(&head, token);
	return head;
}
