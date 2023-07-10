#include "../includes/minishell.h"


// t_token     *new_token()
// {
//     t_token *token;

//     token = (t_token *)ft_calloc(1, sizeof(t_token));
//     token->type = T_WORD;
//     return token;
// }

// void    addttlist(t_list **head, t_token *token)
// {
//     t_list  *new;

//     new = ft_lstnew(token);
//     ft_lstadd_back(head, new);
//     //return 0 시키기 위해서 int형으로 바꿔줘야할듯
// }


// void    tokenization(char *str, int *idx, t_list **head, t_token **token)
// {
//     //    *token = new_token();
//     if (str[*idx] == '|')
//     {
//         (*token)->type = T_PIPE;
//         (*token)->str = ft_strdup("|");
//     }
//     else if (str[*idx] == '\"')
//     {
//         if (str[*idx + 1] == str[*idx])
//         {
//             (*token)->type = T_DOUBLE_Q;
//             (*token)->str = ft_strdup('\""');
//             (*token)->double_flag+=2;
//         }
//         else
//         {
//             (*token)->type = T_DOUBLE_Q;
//             (*token)->str = ft_strdup('\"');
//             (*token)->double_flag++;
//         }
//         (*idx)++;
//     }
//     else if (str[*idx] == '\'')
//     {
//         (*token)->type = T_SINGLE_Q;
//         (*token)->str = ft_strdup('\'');
//         (*token)->single_flag++;
//     }
//     else if (str[*idx] == '>' || str[*idx] == '<')
//     {
//         (*token)->type = T_REDIRECT;
//         if (str[*idx + 1] == str[*idx])
//         {
//             (*token)->str = ft_strncat((*token)->str, &str[*idx], 2);
//             (*idx)++;
//         }
//         else
//         {
//             if (str[*idx] == '<')
//                 (*token)->str = ft_strdup("<");
//             else
//                 (*token)->str = ft_strdup(">");
//         }
//     }
//     else if (str[*idx] == ' ' || str[*idx] == '\t')
//     {
//         // (*idx)++;
//         return ;
//     }
//     addttlist(head, *token);

// }


// t_list *lexer(t_list *list, char *str)
// {
//     int i = 0;
//     int idx = 0;
//     t_token *token = NULL;
//     t_list *head;

//     head = 0;

//     // if (!token)
//     //     return (NULL);
//     int len = ft_strlen(str);
//     while (str[idx])
//     {
//         printf("end : {%s}\n", ft_substr(str, i, idx));
//         if (str[idx] == '\"' || str[idx] == '\'' || str[idx] == '|' || str[idx] == '<' || str[idx] == '>' || str[idx] == ' ' || str[idx] == '\t')
//         {
//             addttlist(&head, token);
//             token = new_token();
//             if (str[idx] != ' ' || str[idx] != '\t')
//                 tokenization(str, &idx, &head, &token); 
//             printf("ex | token_str : %s\n", (*token).str);
//             printf("ex | token_type : %d\n", (*token).type);
//             printf("ex | idx : {{%d}}\n", idx);
//             if (i != idx)
//             {
//                 token = new_token();
//                 (*token).str = ft_substr(str, i, idx);
//                 printf("token_str : [%s]\n", (*token).str);
//                 printf("token_type : %d\n", (*token).type);
//                 printf("in | idx : {{%d}}\n", idx);
//                 addttlist(&head, token);
//             }
//             i = idx + 1;
//         }
//         else if (idx == len - 1)
//         {
//             token = new_token();
//             (*token).str = ft_substr(str, i, idx);
//             addttlist(&head, token);
//             printf("token_str : [%s]\n", (*token).str);
//             printf("token_type : %d\n", (*token).type);
//             printf("in | idx : {{%d}}\n", idx);
//         }
//         idx++;
//     }
//     return (head);
// }

#include "../includes/minishell.h"

t_token *new_token()
{
    t_token *token;
    token = (t_token *)ft_calloc(1, sizeof(t_token));
    token->str = NULL;
    token->type = T_WORD;
    return token;
}

void addttlist(t_list **head, t_token *token)
{
    t_list *new;
    new = ft_lstnew(token);
    ft_lstadd_back(head, new);
}

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

// void tokenization(char *str, int *idx, t_list **head, t_token **token)
// {
//     *token = new_token();
//     if (str[*idx] == '|')
//     {
//         (*token)->type = T_PIPE;
//         (*token)->str = ft_strdup("|");
//     }
//     else if (str[*idx] == '\"')
//     {
//         if (str[*idx + 1] == str[*idx])
//         {
//             (*token)->type = T_DOUBLE_Q;
//             (*token)->str = ft_strdup("\"\"");
//             (*token)->double_flag += 2;
//         }
//         else
//         {
//             (*token)->type = T_DOUBLE_Q;
//             (*token)->str = ft_strdup("\"");
//             (*token)->double_flag++;
//         }
//         (*idx)++;
//     }
//     else if (str[*idx] == '\'')
//     {
//         (*token)->type = T_SINGLE_Q;
//         (*token)->str = ft_strdup("'");
//         (*token)->single_flag++;
//     }
//     else if (str[*idx] == '>' || str[*idx] == '<')
//     {
//         (*token)->type = T_REDIRECT;
//         if (str[*idx + 1] == str[*idx])
//         {
//             (*token)->str = ft_strncat((*token)->str, &str[*idx], 2);
//             (*idx)++;
//         }
//         else
//         {
//             if (str[*idx] == '<')
//                 (*token)->str = ft_strdup("<");
//             else
//                 (*token)->str = ft_strdup(">");
//         }
//     }
//     else if (str[*idx] == ' ' || str[*idx] == '\t')
//     {
//         return;
//     }
//     addttlist(head, *token);
// }

t_list *lexer(t_list *list, char *str)
{
    int i = 0;
    int idx = 0;
    t_token *token = NULL;
    t_list *head = NULL;

    int len = ft_strlen(str);
    while (str[idx])
    {
        if (str[idx] == '\"' || str[idx] == '\'' || str[idx] == '|' || str[idx] == '<' || str[idx] == '>' || str[idx] == ' ' || str[idx] == '\t')
        {
            token = new_token();
            addttlist(&head, token);
            if (str[idx] != ' ' || str[idx] != '\t')
                tokenization(str, &idx, &head, &token);
            if (i != idx)
            {
                token = new_token();
                (*token).str = ft_substr(str, i, idx);
                addttlist(&head, token);
            }
            i = idx + 1;
        }
        else if (idx == len - 1)
        {
            token = new_token();
            (*token).str = ft_substr(str, i, idx);
            addttlist(&head, token);
        }
        idx++;
    }
    return head;
}
