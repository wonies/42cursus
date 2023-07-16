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
void check_dollar(t_data *data, t_token **token, int *i)
{
    char *var = ft_strdup("");
    int var_len = 0;

    ++(*i);
    if (data->tokens->token->re_type == T_HEREDOC)
    {
        printf("HEREDOC CHECK\n");
    }
    if (data->input[*i] == ' ' || data->input[*i] == '\t')
    {
        printf("space check\n");
        while (data->input[*i] == ' ' || data->input[*i] == '\t')
            (*i)++;
        
        if (data->input[*i] != '\0' || data->input[*i] != '|')
        {
            (*token) = new_token();
            (*token)->str = ft_strncat((*token)->str, "$ ", 2);
            --(*i);
        }
        return ; 
    }

    while (data->input[*i] != '\0' && data->input[*i] != ' ' && data->input[*i] != '\t')
    {
        var_len++;
        var = ft_strncat(var, &data->input[*i], 1);
        printf("var value: %s\n", var);
        (*i)++;
    }

    if (possible_env(data, *token, i, var))
    {
        (*token) = new_token();
        (*token)->str = ft_strncat((*token)->str, "$ ", 2);
        (*token)->str = ft_strncat((*token)->str, var, var_len);
        printf("(*token)->str : %s\n", (*token)->str);
        printf("var len ::: %d\n", var_len);
        (*i) -= (var_len + 1);
        return;
    }
}

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

bool    possible_env(t_data *data, t_token *token, int *i, char *var)
{
    char *temp;

    printf("char : %s\n", var);
    temp = find_envp(data, var);
    if (temp != NULL)
    {
        token = new_token();
        char *value = ft_strtok(temp, "=");
        value = ft_strtok(NULL, "=");
        printf("value : %s\n", value);
        token->str = ft_strncat(token->str, value, ft_strlen(value));
        (*i)+= ft_strlen(var);
        token_to_list(&data->tokens, &token, 0);
        return 0;
    }
    return 1;
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