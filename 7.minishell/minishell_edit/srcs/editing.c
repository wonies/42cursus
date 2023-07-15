// #include "../includes/minishell.h"


// void  *lexer(t_data *data)
// {
//     int         i;
//     t_token     *token;

//     token = new_token();
//     i = -1;
//     while (data->input[++i])
//         check_str(data, &token, &i);
//     if (token->str)
//         add_to_list(&data->tokens, &token);
// }

// void    check_str(t_data *data, t_list **token, int *i)
// {
//     if (data->input[*i] == '|' || data->input[*i] == '>' || data->input[*i] == '<')
//     {
//         if ((*token)->token->str)
//             add_to_list(data);
//     }
// }