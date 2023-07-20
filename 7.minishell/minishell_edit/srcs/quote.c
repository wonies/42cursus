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


void    double_quotes(t_data *data, t_token **token, int *i)
{
    (*i)++;
    int start = *i;
    int end = find_closing_quote(start, data->input, '\"');
    char    *temp;
    printf("end size: %d\n", end);
    temp = ft_strdup("");
    char    *prove_env;
    int len = 0;

    prove_env = NULL;
    if (end >= 0)
    {
        if (!(*(*token)->str))
            (*token) = new_token();
        if (end == 0)
        {
            (*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
            return;
        }
        else if (end % 2 != 0)
        {
            printf("end check ----\n");
            while (end != 0)
            {
                if (data->input[*i] == '$')
                {
                    (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                    {
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                        // (*i) += ft_strlen(temp);
                    }
                    else
                        (*i) -= ft_strlen(temp);
                }
                if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
                printf("end :: {%s}\n", (*token)->str);
                printf("end ?? {%d}\n", end);
                if (data->input[*i] == '\"')
                {
                    end--;
                    if (end == 0)
                        break;
                    (*i)++;
                }
                (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
            }
        }
        else if (end % 2 == 0)
        {
            printf("moduler -- \n");
            while (end != 0)
            {
                if (data->input[*i] == '$')
                {
                    (*i)++;
                    while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
                        temp = ft_strncat(temp, &data->input[(*i)++], 1);
                    prove_env = possible_env_char(data, token, i, temp);
                    if (prove_env)
                    {
                        (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
                        // (*i) += ft_strlen(temp);
                    }
                    else
                        (*i) -= ft_strlen(temp);
                }
                if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
                    (*i)++;
                if ((end % 2 != 0) && data->input[*i] == '\"')
                {
                    if (data->input[*i] == '\"')
                    {
                        end--;
                        if (end == 0)
                            break;
                        (*i)++;
                    }
                }
                else
                {
                    if (data->input[*i] == '\"')
                    {
                        end--;
                        if (end == 0)
                            break;
                    }
                }
                
                (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
            }
        }   
    }
}


// void    double_quotes(t_data *data, t_token **token, int *i)
// {
//       (*i)++;
//     int start = *i;
//     int end = find_closing_quote(start, data->input, '\"');
//     char    *temp;
//     printf("end size: %d\n", end);
//     temp = ft_strdup("");
//     char    *prove_env;
//     int len = 0;

//     prove_env = NULL;
//     if (end >= 0)
//     {
// 		if (!(*(*token)->str))
// 			(*token) = new_token();
//         if (end == 0)
// 		{
// 			(*token)->str = ft_strncat((*token)->str, &data->input[--(*i)], 1);
// 			return ;
// 		}
// 		else if (end % 2 != 0)
// 		{
// 			printf("end check ----\n");
//             while (end != 0)
// 			{
// 			    if (data->input[*i] == '$')
//                 {
//                     (*i)++;
//                     while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
//                         temp = ft_strncat(temp, &data->input[(*i)++], 1);
//                     prove_env = possible_env_char(data, token, i, temp);
//                     if (prove_env)
//                     {
//                         (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
//                         // (*i) += ft_strlen(temp);
//                     }
//                     else
//                         (*i) -= ft_strlen(temp);
//                 }
//                 if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
//                     (*i)++;
//                 (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
// 				printf("end :: {%s}\n", (*token)->str);
//                 if (data->input[*i] == '\"')
// 				{
// 					end--;
//                     if (end == 0)
//                         break ;
// 					(*i)++;
// 				}
// 			}
// 		}
//         else if (end % 2 == 0)
//         {
//             printf("moduler -- \n");
//             while (end != 0)
//             {
//                   if (data->input[*i] == '$')
//                 {
//                     (*i)++;
//                     while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
//                         temp = ft_strncat(temp, &data->input[(*i)++], 1);
//                     prove_env = possible_env_char(data, token, i, temp);
//                     if (prove_env)
//                     {
//                         (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
//                         // (*i) += ft_strlen(temp);
//                     }
//                     else
//                         (*i) -= ft_strlen(temp);
//                 }
//                 if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
//                     (*i)++;
//                 if ((end % 2 != 0) && data->input[*i] == '\"')
//                 {
//                     if (data->input[*i] == '\"')
//                     {
//                         end--;
//                         if (end == 0)
//                             break ;
//                         (*i)++;
//                     }
//                 }
//                 else
//                 {
//                     if (data->input[*i] == '\"')
//                     {
//                         end--;
//                         if (end == 0)
//                             break ;
//                     }
//                 }
                
//                 (*token)->str = ft_strncat((*token)->str, &data->input[(*i)++], 1);
//             }
//         }   
    
// 	}
    
  
    // (*i)++;
    // int start = *i;
    // int end = find_closing_quote(start, data->input, '\"') - 1;
    // char    *temp;
    // printf("end size: %d\n", end);
    // temp = ft_strdup("");
    // char    *prove_env;
    // int len = 0;

    // prove_env = NULL;
    // if (end >= 0)
    // {
    //     printf("1----------\n");
    //     if (!(*(*token)->str))
    //         (*token) = new_token();
    //     printf("2----------\n");
    //     while (data->input[*i] != '\"')
    //     {
    //         printf("3----------\n");
    //         if (data->input[*i] == '$')
    //         {
    //             printf("dollarcheck!!!!!!!!!!\n");
    //             (*i)++;
    //             while (data->input[*i] != ' ' && data->input[*i] != '\t' && data->input[*i] != '\"')
    //             {
    //                 printf("4-----------\n");
    //                 temp = ft_strncat(temp, &data->input[(*i)++], 1);
    //             }
    //             printf("temp : ---- %s ---- \n", temp);
    //             // (*i)++;
    //             prove_env = possible_env_char(data, token, i, temp);
    //             printf("prove env : %s\n", prove_env);
    //             if (prove_env != NULL)
    //             {
    //                 (*token)->str = ft_strncat((*token)->str, prove_env, ft_strlen(prove_env));
    //                 printf("token->str : %s\n", (*token)->str);
    //                 // (*i) += ft_strlen(temp);
    //                 printf("{%d}\n", *i);
    //                 printf("[%c]\n", data->input[*i]);
    //             }
    //             // else
    //             //     (*i) -= (len - 1);
    //         }
    //         if (data->input[*i] == '\\' && data->input[*i + 1] == '\\')
    //             (*i)++;
    //         (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
    //         (*i)++;
    //     }
    // }
    // else
    // {
    //     (*token)->str = strncat((*token)->str, &data->input[start - 1], strlen(&data->input[start - 1]));
    //     (*i) = strlen(data->input) + 1;
    // }

//}


// void double_quotes(t_data *data, t_token **token, int *i)
// {
//     (*i)++;
//     int start = *i;
//     int end = find_closing_quote(start, data->input, '\"') - 1;
//     char    *dollar_var;
//     int check = 0;
//     printf("end ::::: %d\n", end);
//     dollar_var = strdup("");
//     int env = 0;
//     int len = 0 ;

//    // if (end >= 0)
//     while (data->input[*i] != ' ' || data->input[*i] != '\t')
//     {
//         if (data->input[*i] == '$')
//         {
//             len = *i;
//             *i++;
//             while (data->input[*i] != ' ' || data->input[*i] != '\t' || data->input[*i] != '\0' || data->input[*i] != '\"')
//             {
//                 dollar_var = ft_strncat(dollar_var, &data->input[*i++], 1);
//             }
//             check = possible_env_char(data, token, i, dollar_var);
//             if (check != -1)
//             {
                
//             }
//         }
//     }

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
//     if (end >= 0)
//     {
//         int length = end - start;
//         printf("length : %d\n", length);
//         char *str = malloc(length + 1);
//         // if ((possible_env(data, token, i, str))== 1)
//         //     return ;
//         strncpy(str, &data->input[start], length);
//         printf("check str : %s\n", str);
//         str[length] = '\0';
//         check = possible_env(data, token, i, str);
//         if (!check)
//         {
//             (*i) += ft_strlen(str) + 1;
//         }
//         --(*i);
//         if (check)
//         {
//             if (str)
//             (*token)->str = strncat((*token)->str, str, length);
//             free(str);
//             (*i) = end + 1;
//         }

//     }
//     else
//     {
//         (*token)->str = strncat((*token)->str, &data->input[start - 1], strlen(&data->input[start - 1]));
//         (*i) = strlen(data->input) + 1;
//     }
// }

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

// // int find_closing_quote(int i, char *str, char quote)
// // {
// //     if (quote == '\"')
// //     {
// //         while (str[i] != '\0' && str[i] != quote)
// //         {
// //             if (str[i] == '\\' && str[i + 1] == quote)
// //                 i++;
// //             i++;
// //         }
// //         if (str[i] == quote)
// //             return i;
// //     }
// //     else
// //     {
// //         while (str[i] != '\0' && str[i] != quote)
// //             i++;
// //         if (str[i] == quote)
// //             return i;
// //     }
// //     return -1;
// // }

// // int find_closing_quote(int i, char *str, char quote)
// // {
// //     int len = strlen(str);
// //     int escape = 0;
// //     while (i < len)
// //     {
// //         if (str[i] == quote && !escape)
// //             return i;
// //         escape = (str[i] == '\\' && !escape);
// //         i++;
// //     }
// //     return -1;
// // }

// int	find_closing_quote(int i, char *input, char quote)
// {
//     if (quote == '\"')
//     {
//         while (input[i] != '\0')
//         {
//             if (input[i] == quote)
//             {
//                 return (i);
//             }
//             i++;
//         }
//     }
//     else
//     {
//         while (input[i] != '\0')
//         {
//             if (input[i] == quote)
//                 return (i);
//             i++;
//         }
//     }
// 	return (-1); 

//원래하던거!!!!
// }


int	find_closing_quote(int i, char *input, char quote)
{
    int len = 0;

    if (quote == '\"')
    {
        while (input[i] != '\0')
        {
            if (input[i] == quote)
            {
                len++;
                printf("len : %d\n", len);
            }
            i++;
        }
        return (len);
    }
    else
    {
        while (input[i] != '\0')
        {
            if (input[i] == quote)
                return (i);
            i++;
        }
    }
	return (-1);
}

// 만약에 len == 0 이면, "가 앞에 하나라는 뜻. 그러면 바로 토큰화 시키기.
// 만약에 len == 1 이면 " 이 안에 들어온다는 뜻 "
// 만약에 len == 2 이면 """ 가 세개라는 뜻 " " 안에 있는 "를 문자열 취급.
// 만약에 len == 3 이면 """" 라는 뜻
// 만약에 len == 4 이면 """"" 라는 뜻... -> """"안에 있는 "를 문자열 취급

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
