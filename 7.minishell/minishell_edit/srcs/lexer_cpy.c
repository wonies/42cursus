#include "../includes/minishell.h"

// t_token *new_token()
// {
// 	t_token *token;

// 	token = (t_token *)ft_calloc(1, sizeof(t_token));
// 	token->str = NULL;
// 	token->type = T_WORD;
	
// 	return token;
// }

// void	addttlist(t_list **head, t_token *token)
// {
// 	t_list *new;

// 	new = ft_lstnew(token);
// 	ft_lstadd_back(head, new);
// }

void tokenization(char *str, int *idx, t_list **head, t_token **token)
{
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
            (*token)->str = ft_strdup(&str[*idx]);
            (*idx)++;
        }
        else
        {
            if (str[*idx] == '<')
                (*token)->str = ft_strdup("<");
            else
                (*token)->str = ft_strdup(">");
        }
    }
    else if (str[*idx] == ' ' || str[*idx] == '\t')
    {
        return;
    }
    addttlist(head, *token);
}


// t_list *lexer(t_list *lst, char *str)
// {
// 	int	i;
// 	int	idx;
// 	t_token *token;
// 	t_list *head;

// 	i = 0;
// 	idx = 0;
// 	token = NULL;
// 	head = NULL;
// 	while (str[idx])
// 	{
// 		if (str[idx] == '\"' || str[idx] == '\'' || str[idx] == '|' || str[idx] == '<' || str[idx] == '>' || str[idx] == ' ' || str[idx] == '\t')
// 		{
// 			token = new_token();
// 			tokenization(str, &idx, &head, &token);
// 			addttlist(&head, token);
// 			i = idx + 1;
// 		}
// 		else
// 		{
// 			if (i != idx)
// 			{
// 				token = new_token();
// 				(*token).str = ft_substr(str, i, idx);
// 				printf("token_str : [%s]\n", (*token).str);
//                 printf("token_type : %d\n", (*token).type);
// 				addttlist(&head, token); 
// 			}
// 		}
// 		idx++;
// 	}
// 	return (head);
// }

// t_list *lexer(char *str)
// {
//     t_list *head = NULL;
//     int len = strlen(str);
//     int i = 0;
//     int idx = 0;
//     char *token_str = NULL;

//     while (idx < len)
//     {
//         if (str[idx] == ' ' || str[idx] == '\t')
//         {
//             if (token_str != NULL)
//             {
//                 t_token *token = new_token(0, token_str);
//                 addttlist(&head, token);
//                 token_str = NULL;
//             }
//         }
//         else if (str[idx] == '<' || str[idx] == '>' || str[idx] == '|')
//         {
//             if (token_str != NULL)
//             {
//                 t_token *token = new_token(0, token_str);
//                 addttlist(&head, token);
//                 token_str = NULL;
//             }
//             char symbol[2] = {str[idx], '\0'};
//             t_token *token = new_token(1, symbol);
//             addttlist(&head, token);
//         }
//         else
//         {
//             if (token_str == NULL)
//                 i = idx;
//             idx++;
//             continue;
//         }
//         idx++;
//     }

//     if (token_str != NULL)
//     {
//         t_token *token = new_token(0, token_str);
//         addttlist(&head, token);
//     }

//     return head;
// }

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

t_token *new_token(int type, char *str)
{
    t_token *token = malloc(sizeof(t_token));
    if (token)
    {
        token->type = type;
        token->str = strdup(str);
    }
    return token;
}

void addttlist(t_list **head, t_token *token)
{
    t_list *new = ft_lstnew(token);
    ft_lstadd_back(head, new);
}

t_list *lexer(t_list *list, char *str)
{
    t_list *head = NULL;
    int len = strlen(str);
    int i = 0;
    int idx = 0;
    char *token = NULL;

	while (idx < len)
	{
		if (str[idx] == '<' || str[idx] == '>' || str[idx] == '|' || str[idx] == '\"' || str[idx] == '\'')
		{
			token = new_token()
		}
	}
    while (idx < len)
    {
        if (str[idx] == ' ' || str[idx] == '\t')
        {
            if (token_str != NULL)
            {
                t_token *token = new_token(0, token_str);
                addttlist(&head, token);
            }
        }
        else if (str[idx] == '<' || str[idx] == '>' || str[idx] == '|' || str[idx] == '\"' || str[idx] == '\'')
        {
            if (token_str != NULL)
            {
                t_token *token = new_token(1, token_str);
				tokenization(str, &idx, &head, &token);
                addttlist(&head, token);
            }
            char symbol[2] = {str[idx], '\0'};
            t_token *token = new_token(1, symbol);
            addttlist(&head, token);
        }
        else
        {
            if (token_str == NULL)
                i = idx;
            idx++;
            continue;
        }
        idx++;
    }

    if (token_str != NULL)
    {
        t_token *token = new_token(0, token_str);
        addttlist(&head, token);
    }

    return head;
}