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
	token->str = NULL;
	token->type = T_WORD;
	
	return token;
}

void	addttlist(t_list **head, t_token *token)
{
	t_list *new;

	new = ft_lstnew(token);
	ft_lstadd_back(head, new);
}


void tokenization(char *str, int *idx, t_list **head, t_token **token)
{
    *token = new_token();
    if (str[*idx] == '|')
    {
        (*token)->type = T_PIPE;
        (*token)->str = ft_strdup("|");
    }
    else if (str[*idx] == '\"')
    {
        if (str[*idx + 1] == str[*idx])
        {
            (*token)->type = T_DOUBLE_Q;
            (*token)->str = ft_strdup("\"\"");
            (*token)->double_flag += 2;
        }
        else
        {
            (*token)->type = T_DOUBLE_Q;
            (*token)->str = ft_strdup("\"");
            (*token)->double_flag++;
        }
        (*idx)++;
    }
    else if (str[*idx] == '\'')
    {
        (*token)->type = T_SINGLE_Q;
        (*token)->str = ft_strdup("'");
        (*token)->single_flag++;
    }
    else if (str[*idx] == '>' || str[*idx] == '<')
    {
        (*token)->type = T_REDIRECT;
        if (str[*idx + 1] == str[*idx])
        {
            (*token)->str = ft_strncat((*token)->str, &str[*idx], 2);
            (*idx)++;
        }
        else
        {
            if (str[*idx] == '<')
                (*token)->str = ft_strdup("<");
            else
                (*token)->str = ft_strdup(">");
			(*idx)++;
        }
    }
    else if (str[*idx] == ' ' || str[*idx] == '\t')
    {
        (*token)->type = T_SPACE;
		(*idx)++;
    }
    addttlist(head, *token);
}

t_list *lexer(t_list *list, char *str)
{
	t_list *head;
	t_token *token;
	int	len;
	int	i;
	int check;

	head = NULL;
	token = NULL;
	i = 0;
	check = 0;
	len = ft_strlen(str);
	token = new_token();
	while (i < len)
	{
		printf("check str : {%c}\n", str[i]);
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '<' || str[i] == '>' || str[i] == '|' || str[i] == '\"' || str[i] == '\'')
        {
	//		token = new_token();
			addttlist(&head, token);
			tokenization(str, &i, &head, &token);
			token = new_token();
			// addttlist(&head, token);
			// if (i != check)
            // {
            //     token = new_token();
            //     (*token).str = ft_substr(str, check, i);
			// 	printf("token str : %d & %d, %s\n",check, i,   (*token).str);
            //     addttlist(&head, token);
            // }
			check = i + 1;
		}
		else
		{
			(*token).str = ft_strncat(token->str, &str[i], 1);
		}
        // else if ((i = len - 1))
        // {
		// 	token = new_token();
		// 	(*token).str = ft_substr(str, check, i + 1);
		// 	addttlist(&head, token);
        // }
		i++;
	}
	return head;
}
