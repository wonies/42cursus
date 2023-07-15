#include "../includes/minishell.h"

void    double_quotes(t_data *data, t_token **token, int *i)
{
    
    find_quote(*i, data->input, '\"');
    // while (data->input[++(*i)])
    // {
    //     if (data->input[*i] == '\"')
    //         break;
    //     (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
    // }

//     if (find_quote(*i, data->input, '\"') == 1)
//     {    
//    //     (*token)->str = ft_strncat((*token)->str, "\"", 1);
//         while (data->input[++(*i)])
//         {
//             printf("{%c}", data->input[*i]);
//             (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1); 
//         }
//         // (*i)++;
//         // return ;
//     }
}

void    single_quotes(t_data *data, t_token **token, int *i)
{

    if (find_quote(*i, data->input, '\'') == 1)
    {    
        (*token)->str = ft_strncat((*token)->str, "\'", 1);
        (*i)++;
        return ;
    }
    while (data->input[++(*i)])
    {
        (*token)->str = ft_strncat((*token)->str, &data->input[*i], 1);
    }
}

bool    find_quote(int i, char *str, char quote)
{
    // while (str[i] == quote || str[i] == '\0')
    // {
    //     if (str[i] == '\\' && str[i++] == quote)
    //         i++;
    //     i++;
    // }
    // if (str[i] == '\0')
    // {
    //     printf("[%c]\n", str[i]);
    //     return (0);
    // }
    // return (1);

    while (str[i] == quote)
    {
        printf("quote: %d\n", i);
        printf("{{%c}}\n", str[i]);
        i++;
    }
    return 0;
}
