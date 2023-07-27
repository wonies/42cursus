#include "../includes/minishell.h"

// void    env_dollor(t_data *data, t_token *token, int *i)
// {
//     char    *var;

//     ++(*i);
//     var = NULL;
//     printf("why SEG???\n");
//     while (data->input[*i])
//     {
//         var = ft_strncat(var, &data->input[*i], 1);
//         printf("var value : %s\n", var);
//         (*i)++;
//     }
//     // while (data->input[*i] != ' ' || data->input[*i] != '\t' || data->input[*i] == '\0')
//     // {
//     //     var = ft_strncat(var, &data->input[*i], 1);
//     //     printf("var check : %s\n", var);
//     //     (*i)++;
//     // }
    
//    // possible_env(data, token, i, var);
// }
// void	not_env(t_data *data, int *i, t_token **token, char *var, int var_len)
// {
// 	// t_token	**token;

// 	if (!(*(*token)->str))
// 		(*token) = new_token();
// 	if (data->input[*i] != ' ' || data->input[*i] != '\t')
// 	{
// 		(*token)->str = ft_strncat((*token)->str, "$", 1);
// 		(*i) -= (var_len + 1);
// 		return ;
// 	}
// 	(*token)->str = ft_strncat((*token)->str, "$ ", 2);
// 	(*token)->str = ft_strncat((*token)->str, var, var_len);
// 	printf("(*token)->str : %s\n", (*token)->str);
// 	printf("var len ::: %d\n", var_len);
// 	(*i) -= (var_len + 1);
// }


// void not_env(t_data *data, int *i, char *var, int var_len)
// {
//     t_token *token = *(&(data->tokens)); // token에 할당

//     printf("--------------------check2!!\n");
//     if (!(token->str))
//         token = new_token();
//     printf("--------------------check3!!\n");
//     if (data->input[*i] != ' ' || data->input[*i] != '\t')
//     {
//         printf("------------------check4!!\n");
//         token->str = ft_strncat(token->str, "$", 1);
//         printf("%s\n", token->str);
//         (*i) -= (var_len + 1);
//         return;
//     }
//     token->str = ft_strncat(token->str, "$ ", 2);
//     token->str = ft_strncat(token->str, var, var_len);
//     printf("token->str : %s\n", token->str);
//     printf("var len ::: %d\n", var_len);
//     (*i) -= (var_len + 1);
// }

// void not_env(t_data *data, int *i, char *var, int var_len)
// {
//     t_token *token = *(&(data->tokens)); // token에 할당
//     printf("--------------------check2!!\n");
//     if (!(token->str))
//         token = new_token();
//     printf("--------------------check3!!\n");
//     if (data->input[*i] != ' ' || data->input[*i] != '\t')
//     {
//         printf("------------------check4!!\n");
//         *(*token).str = *ft_strncat(token->str, "$", 1);
//         if (!(token->str))
//             printf("bash");
//         printf("check token's str : %s\n", token->str);
//         (*i) -= (var_len + 1);
//         return;
//     }
//     token->str = ft_strncat(token->str, "$ ", 2);
//     token->str = ft_strncat(token->str, var, var_len);
//     printf("token->str : %s\n", token->str);
//     printf("var len ::: %d\n", var_len);
//     (*i) -= (var_len + 1); // -> US만 출력!!!
// }

// void not_env(t_data *data, int *i, char *var, int var_len)
// {
//     t_token *token = *(&(data->tokens)); // token에 할당
//     printf("--------------------check2!!\n");
//     if (!(token->str))
//         token = new_token();
//     printf("--------------------check3!!\n");
//     if (data->input[*i] != ' ' || data->input[*i] != '\t')
//     {
//         printf("------------------check4!!\n");
//         token->str = ft_strncat(token->str, "$", 1);
//         if (!(token->str))
//             printf("bash");
//         printf("check token's str : %s\n", token->str);
//         (*i) -= (var_len + 1);
//         return;
//     }
//     token->str = ft_strncat(token->str, "$ ", 2);
//     token->str = ft_strncat(token->str, var, var_len);
//     printf("token->str : %s\n", token->str);
//     printf("var len ::: %d\n", var_len);
//     (*i) -= (var_len + 1);

//     // 추가된 코드: 토큰을 리스트에 추가
    
// }



// void not_env(t_data *data, int *i, char *var, int var_len)
// {
//     t_token **token = &(data->tokens); // token에 할당

//     if (!(*(*token)->str))
//         (*token) = new_token();
//     if (data->input[*i] != ' ' || data->input[*i] != '\t')
//     {
//         (*token)->str = ft_strncat((*token)->str, "$", 1);
//         (*i) -= (var_len + 1);
//         return;
//     }
//     (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//     (*token)->str = ft_strncat((*token)->str, var, var_len);
//     printf("(*token)->str : %s\n", (*token)->str);
//     printf("var len ::: %d\n", var_len);
//     (*i) -= (var_len + 1);
// }

void	not_env(t_data *data, t_token **token, int *i, char *var)
{
	int	var_len;

    printf("not env-------------\n");
	var_len = ft_strlen(var);
	if (!(*(*token)->str))
		(*token) = new_token();
	if (data->input[*i] != ' ' || data->input[*i] != '\t')
	{
		(*token)->str = ft_strncat((*token)->str, "$", 1);
		(*i) -= (var_len );
		return ;
	}
	(*token)->str = ft_strncat((*token)->str, "$ ", 2);
	(*token)->str = ft_strncat((*token)->str, var, var_len);
	printf("(*token)->str : %s\n", (*token)->str);
	printf("var len ::: %d\n", var_len);
	(*i) -= (var_len + 1);
}

bool	check_heredoc(t_data *data, t_token **token, int *i)
{
	if (data->tokens && data->tokens->token->re_type == T_HEREDOC)
	{
		(*token)->str = ft_strncat((*token)->str, "$", 1);
		--(*i);
		return 1;
	}
	return 0;
}

bool	check_space(t_data *data, t_token **token, int *i)
{
	t_token *prev = NULL;

    if (data->input[*i] == ' ' || data->input[*i] == '\t')
    {
        // if (data->tokens->pre)
        //     printf("check PIPE : %d\n", data->tokens->pre->token->type);
        if ((!(data->tokens)))
        {
            // if (!(*(*token)->str))
            // if (data->tokens->pre && data->tokens->pre->token->type == T_PIPE)
            (*token) = new_token();
            (*token)->str = ft_strncat((*token)->str, "$", 1);
            token_to_list(&data->tokens, token, 1);
            return 1;
        }
        if (data->tokens)
        {
            prev = ft_lstlast(data->tokens)->token;
            if (prev && prev->type == T_PIPE)
            {
                (*token) = new_token();
                (*token)->str = ft_strncat((*token)->str, "$", 1);
                token_to_list(&data->tokens, token, 1);
                return 1;
            }
        }
        int len = 0;
        while (data->input[*i] == ' ' || data->input[*i] == '\t')
        {
            (*i)++;
            len++;
        }

        /* echo $                 cat -> {echo} {$ cat} 으로 바꿔준 코드 */


        if (data->input[*i] != '\0' || data->input[*i] != '|')
        {
            printf("WHT YOU PASS HERE ??? \n");
            (*token) = new_token();
            (*token)->str = ft_strncat((*token)->str, "$", 1);
            // token_to_list(&data->tokens, token, 1);
            printf("break point : %d\n", len);
            printf("break point : %d\n", len);
            if (len > 0)
                (*token)->str = ft_strncat((*token)->str, " ", 1);
            // while(data->input[*i])
            // {
                // printf("data input : %c\n", data->input[*i]);
                // printf("data input : %c\n", data->input[*i]);
            //     ++(*i);
            // }
            while (data->input[*i] || data->input[*i] == '|')//|| data->input[*i] != '|')
            {
                printf("data input : %c\n", data->input[*i]);
                if (data->input[*i] == '\"' || data->input[*i]== '\'')
                {
                    if (data->input[*i] == '\"')
                        double_quotes(data, token, i, 1);
                    else
                        single_quotes(data, token, i, 1);
                    return 1;
                }
                else
                {
                    len = 0;
                    (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
                } 
            }
            --(*i);
        }
        return 1;
    }
	return 0;
}

/* data->tokens가 NULL인 경우:

data->tokens가 NULL이라는 것은 리스트가 아예 비어있다는 것을 의미합니다.
즉, data->tokens가 아무런 노드도 가지고 있지 않은 상태입니다.
이 상태에서 data->tokens->pre를 접근하려고 하면 세그멘테이션 오류가 발생합니다. 왜냐하면 data->tokens가 NULL이므로 노드의 이전 노드를 가리키는 pre 포인터가 존재하지 않기 때문입니다.
!data->tokens->pre (즉, data->tokens->pre가 NULL인 경우):

data->tokens가 NULL이 아니고, 리스트에 최소한 하나 이상의 노드가 있는 상태입니다.
이때 data->tokens->pre가 NULL이라는 것은 현재 노드의 이전 노드가 존재하지 않는다는 것을 의미합니다.
이는 리스트의 첫 번째 노드인 경우나 이전 노드가 없는 경우에 해당합니다.
따라서 data->tokens->pre를 접근하는 것이 가능합니다.
따라서 !data->tokens->pre은 data->tokens가 비어있지 않고 최소한 하나의 노드를 가지고 있으며, 현재 노드가 첫 번째 노드가 아닌 경우를 확인하는 조건문입니다. 한편, data->tokens가 NULL인 경우는 리스트가 아예 비어있는 상태이며, 이때는 data->tokens->pre를 접근할 수 없습니다. 따라서 이 두 상황은 서로 다른 상황입니다.*/



void	check_dsign(t_data *data, t_token **token, int *i)
{
	t_token *prev;
	char	*var;
	int	var_len;

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
	while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\'' \
		&& data->input[*i] != '\"')
	{
		var_len++;
        printf("{{{{{%c}}}}}\n", data->input[*i]);
        if ((special_character(data->input[*i], 0)) == 1)
        {
            --(*i);
            break ;
        }
		var = ft_strncat(var, &data->input[(*i)++], 1);
	}
	if (possible_env(data, token, i, var))
		not_env(data, token, i, var);
	--(*i);
}

int	special_character(char c, int digit)
{
    if (digit == 0)
    {
        if (c == '~' || c == '@' || c == '#' || c == '%' || c == '$' || c == '^' \
        || c == '&' || c == '*' || c == '(' || c == ')' || c == '=' || c == '+' \
        || c == '{' || c == '}' || c == '/'|| c == '-' || c ==':' || c =='.' || c ==',')
            return 1;
        else
            return 0;
    }
    else
    {
        if (c == '~' || c == '@' || c == '#' || c == '%' || c == '$' || c == '^' \
        || c == '&' || c == '*' || c == '(' || c == ')' || c == '=' || c == '+' \
        || c == '{' || c == '}' || c == '/'|| c == '-' || c == ':' || c == ';' \
        || c == '|' || c == '<' || c == '>' || c == '.' || c == ',') 
            return 1;
        else
            return 0;
    }
}








// void check_dollar(t_data *data, t_token **token, int *i)
// {
//     t_token *prev = NULL;
//     char *var = ft_strdup("");
//     if (!var)
//         printf("no!!\n");
//     int var_len = 0;
//     printf("here????\n");
//     ++(*i);
//     if (check_heredoc(data, token, i))
// 		return ;
//     if (check_space(data, token, i))
// 		return ;
//     //printf(" || check PIPE || : %p\n", (*token)->prev);
//     // if ((data->tokens)->token)
//     //     prev = ft_lstlast(data->tokens)->token;
//     // if (prev->type == T_PIPE)
//     //     printf("=========HERE=======\n");
//    // if (data->tokens && data->tokens->pre && data->tokens->pre->token && data->tokens->pre->token->type == T_PIPE)
//     // if (data->input[*i] == '\"' || data->input[*i] == '\'' )
//     // {
//     //     --(*i);
//     //     return ;
//     // }
//     // if (data->tokens && data->tokens->token->re_type == T_HEREDOC)
//     // {
//     //     (*token)->str = ft_strncat((*token)->str, "$", 1);
//     //     --(*i);
//     //     return ;
//     // }
//     // if (data->input[*i] == ' ' || data->input[*i] == '\t')
//     // {
//     //     printf("space check\n");
//     //     while (data->input[*i] == ' ' || data->input[*i] == '\t')
//     //         (*i)++;
        
//     //     if (data->input[*i] != '\0' || data->input[*i] != '|')
//     //     {
//     //         (*token) = new_token();
//     //         (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//     //         --(*i);
//     //     }
//     //     return ; 
//     // }
//     int possible_check = 2;

//     while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] == '\'' \
// 		&& data->input[*i] != '\"')
//     {
//         var_len++;
//         var = ft_strncat(var, &data->input[*i], 1);
//         possible_check = possible_env(data, token, i, var);
//         printf("possible_check :: %d\n", possible_check);
//         if (possible_check == 0)
//             break ;
//         printf("var value: %s\n", var);
//         (*i)++;
//     }
//     if (possible_check == 1)
//     {
//         not_env(data, token, i, var);
//     }
//     // if (possible_env(data, token, i, var))
//     //     not_env(data, token, i, var);
//     (*i)--;
//     // int len = ft_strlen(var);
//     //     if (!(*(*token)->str))
//     //         (*token) = new_token();
//     //     if (data->input[*i] != ' ' || data->input[*i] != '\t')
//     //     {
//     //         (*token)->str = ft_strncat((*token)->str, "$", 1);
//     //         (*i) -= (len + 1);
//     //         return ;
//     //     }
//     //     (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//     //     (*token)->str = ft_strncat((*token)->str, var, len);
//     //     printf("(*token)->str : %s\n", (*token)->str);
//     //     printf("var len ::: %d\n", len);
//     //     (*i) -= (len + 1);
//     //     return;
//     // }
// }

// void check_dollar(t_data *data, t_token **token, int *i)
// {
//     char *var = ft_strdup("");
//     int var_len = 0;

//     ++(*i);
//     if (data->input[*i] == ' ' || data->input[*i] == '\t')
//     {
//         printf("space check\n");
//         while (data->input[*i] == ' ' || data->input[*i] == '\t')
//             (*i)++;
        
//         if (data->input[*i] == '\0' || data->input[*i] == '|')
//         {
//             (*token) = new_token();
//             (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//             return;
//         }
//     }

//     while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t')
//     {
//         var_len++;
//         var = ft_strncat(var, &data->input[*i], 1);
//         printf("var value: %s\n", var);
//         (*i)++;
//     }

//     if (possible_env(data, *token, i, var))
//     {
//         (*token) = new_token();
//         (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//         (*token)->str = ft_strncat((*token)->str, var, var_len);
//         printf("(*token)->str : %s\n", (*token)->str);
//         printf("var len ::: %d\n", var_len);
//         (*i) -= var_len;
//         return;
//     }
// }
// void check_dollar(t_data *data, t_token **token, int *i)
// {
//     char *var = ft_strdup("");
//     int var_len = 0;

//     ++(*i);
//     if (data->input[*i] == ' '  || data->input[*i] == '\t')
//     {
//         printf("space check\n");
//         while (data->input[*i] == ' ' || data->input[*i] == '\t')
//             (*i)++;
//          if (data->input[*i] == '\0' || data->input[*i] == '|')
//     {
//         (*token) = new_token();
//         (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//         return;
//     }
//         // while (data->input[*i] == '\0' || data->input[*i] == '|')
//         // {
//         //     if (data->input[*i] == ' ')
//         //         (*i)++;
//         //     var = ft_strncat(var, &data->input[*i++], 1);
//         // }
//         // (*token) = new_token();
//         // (*token)->str = ft_strncat((*token)->str, "$ ", 2);
//         // //(*token)->str = ft_strncat((*token)->str, var, ft_strlen(var));
//         // (*i) += ft_strlen(var);
//         // token_to_list(&data->tokens, token, *i);
//         return ;
//     }

//     while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t')
//     {
//         var_len++;
//         var = ft_strncat(var, &data->input[*i], 1);
//         printf("var value: %s\n", var);
//         (*i)++;
//     }
    
//     if ((possible_env(data, *token, i, var)))
//     {
//         (*token) = new_token();
//         (*token)->str = ft_strncat((*token)->str, "$", 1);
//         printf("(*token)->str : %s\n", (*token)->str);
//         printf("var len ::: %d\n", var_len);
//         (*i) -= (var_len + 1);
//         return ;
//     }   

//     // char *var = NULL;
// }

bool    possible_env(t_data *data, t_token **token, int *i, char *var)
{
    char *temp;

    printf("char : %s\n", var);
    temp = find_envp(data, var);
    if (temp != NULL)
    {
        if (!(*(*token)->str))
            (*token) = new_token();
        char *value = ft_strtok(temp, "=");
        value = ft_strtok(NULL, "=");
        printf("value : %s\n", value);
        (*token)->str = ft_strncat((*token)->str, value, ft_strlen(value));
        (*i)+= 1;
        // (*i)+= ft_strlen(var);
        // token_to_list(&data->tokens, token, 0);
        return 0;
    }
    return 1;
}


char    *possible_env_char(t_data *data, t_token **token, int *i, char *var)
{
    char    *temp;

    temp = find_envp(data, var);
    printf("%s\n", temp);
    if (temp != NULL)
    {
        char *value = ft_strtok(temp, "=");
        value = ft_strtok(NULL, "=");
        printf("prove value :: %s\n", value);
        return (value);
    }
    return NULL;
}


// void    possible_env(t_data *data, t_token *token, int *i, char *var)
// {
//     t_list  *temp;

//     temp = find_envp(data, var);
//     printf("%s\n", temp->env);
//     // if (temp != NULL)
//     // {
//     //     temp = 
//     // }        
// }