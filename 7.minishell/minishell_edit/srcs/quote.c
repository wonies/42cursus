#include "../includes/minishell.h"
// void double_quotes(t_data *data, t_token **token, int *i)
// {
//     while (data->input[++(*i)])
//     {
//         if (data->input[*i] == '\"')
//         {
//             // 현재 문자가 따옴표인 경우, 따옴표를 추가한 후 토큰화
//             (*token)->str = ft_strncat((*token)->str, "\"", 1);
//             token_to_list(&data->tokens, token, 1);
//             break;
//         }
//         (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//     }
// }
// void    double_quotes(t_data *data, t_token **token, int *i)
// {
    
//     find_quote(*i, data->input, '\"');

//     // if (find_quote(*i, data->input, '\"'))
//     // {
//     //     while 
//     // }
//     // while (data->input[++(*i)])
//     // {
//     //     if (data->input[*i] == '\"')
//     //         break;
//     //     (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//     // }

// //     if (find_quote(*i, data->input, '\"') == 1)
// //     {    
// //    //     (*token)->str = ft_strncat((*token)->str, "\"", 1);
// //         while (data->input[++(*i)])
// //         {
// //             printf("{%c}", data->input[*i]);
// //             (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1); 
// //         }
// //         // (*i)++;
// //         // return ;
// //     }
//     if (find_quote(*i, data->input, '\"') == 1)
//     {    
//         (*token)->str = ft_strncat((*token)->str, "\"", 1);
//         //(*i)++;
//         return ;
//     }
//     while (data->input[++(*i)])
//     {
//         (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//     }
// }
// void double_quotes(t_data *data, t_token **token, int *i)
// {
//     (*i)++;
//     int start = *i;
//     int end = find_quote(*i, data->input, '\"');
//     if (end >= 0)
//     {
//         (*token)->str = ft_substr(data->input, start, end - start);
//         (*i) = end + 1;
//     }
//     else
//     {
//         while (data->input[*i])
//         {
//             (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//             (*i)++;
//         }
//     }
// }


void double_quotes(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int start = *i;
    int end = find_closing_quote(start, data->input, '\"') - 1;
    char    *dollar_var;
    int check = 0;
    printf("end ::::: %d\n", end);
    dollar_var = strdup("");
    int env = 0;
    int len = 0 ;

    while (data->input[*i] != ' ' || data->input[*i] != '\t')
    {
        if (data->input[*i] == '$')
        {
            len = *i;
            env = check_dollar(data, token, i);
        }
        if (env == 1)
        {
            
        }


    }

    // if (data->input[*i] == '$')
    // {
    //     ++(*i);
    //     while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
    //         dollar_var = strncat(dollar_var, &data->input[(*i)++], 1);
    //     printf("dollar var ::: %s\n", dollar_var);
    //     check = possible_env(data, token, i, dollar_var);
    //     if (!check)
    //     {
    //         (*i) += ft_strlen(dollar_var) + 1;
    //         return ;
    //     }
    //     --(*i);
    // }
    if (end >= 0)
    {
        int length = end - start;
        printf("length : %d\n", length);
        char *str = malloc(length + 1);
        // if ((possible_env(data, token, i, str))== 1)
        //     return ;
        strncpy(str, &data->input[start], length);
        printf("check str : %s\n", str);
        str[length] = '\0';
        check = possible_env(data, token, i, str);
        if (!check)
        {
            (*i) += ft_strlen(str) + 1;
        }
        --(*i);
        if (check)
        {
            if (str)
            (*token)->str = strncat((*token)->str, str, length);
            free(str);
            (*i) = end + 1;
        }

    }
    else
    {
        (*token)->str = strncat((*token)->str, &data->input[start - 1], strlen(&data->input[start - 1]));
        (*i) = strlen(data->input) + 1;
    }
}

void single_quotes(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int start = *i;
    int end = find_closing_quote(start, data->input, '\'');
    if (end >= 0)
    {
        int length = end - start;
        char *str = malloc(length + 1);
        strncpy(str, &data->input[start], length);
        str[length] = '\0';
        (*token)->str = strncat((*token)->str, str, length);
        free(str);
        (*i) = end;
    }
    else
    {
        (*token)->str = strncat((*token)->str, &data->input[start - 1], strlen(&data->input[start - 1]));
        (*i) = strlen(data->input) - 1;
    }
}

// int find_closing_quote(int i, char *str, char quote)
// {
//     if (quote == '\"')
//     {
//         while (str[i] != '\0' && str[i] != quote)
//         {
//             if (str[i] == '\\' && str[i + 1] == quote)
//                 i++;
//             i++;
//         }
//         if (str[i] == quote)
//             return i;
//     }
//     else
//     {
//         while (str[i] != '\0' && str[i] != quote)
//             i++;
//         if (str[i] == quote)
//             return i;
//     }
//     return -1;
// }

// int find_closing_quote(int i, char *str, char quote)
// {
//     int len = strlen(str);
//     int escape = 0;
//     while (i < len)
//     {
//         if (str[i] == quote && !escape)
//             return i;
//         escape = (str[i] == '\\' && !escape);
//         i++;
//     }
//     return -1;
// }

int	find_closing_quote(int i, char *input, char quote)
{
	while (input[i] != '\0')
	{
		if (input[i] == '\\')
			i++;
		if (input[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}


// void    double_quotes(t_data *data, t_token **token, int *i)
// {
//     int idx;

//     (*i)++;
//     idx = find_quote(*i, &data->input[*i], '\"');
//     if (idx > 0)
//     {
//         (*token)->str = ft_substr(&data->input[*i], *i, idx);
//         printf("check token str: %s\n", (*token)->str);
//     }
//     else
//     {
//         while (data->input[(*i)])
//         {
//             (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//             (*i)++;
//         }
//     }
// }

// void    single_quotes(t_data *data, t_token **token, int *i)
// {
//     int idx;
//     if ((idx == (find_quote(*i, &data->input[*i], '\''))) > 0)
//     {    
//         (*token)->str = ft_substr((*token)->str, *i, idx);
//         printf("~~~~~~~~~token str ~~~~~~~~: %s\n", (*token)->str);
//         // return ;
//     }
//     while (data->input[++(*i)])
//     {
//         (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
//     }
// }



// int    find_quote(int i, char *str, char quote)
// {
//     while (str[i] == quote || str[i] == '\0')
//     {
//         if (str[i] == '\\' && str[i++] == quote)
//             i++;
//         i++;
//     }
//     if (str[i] == '\0')
//         return (0);
//     return (i);
// }
