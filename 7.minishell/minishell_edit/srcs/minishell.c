#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    t_list *list = NULL;
    t_data *data = NULL;
    // str = ft_strdup("ls -al < a | grep  "" | cat -e | head -3 >> outfile");
    // str = ft_strdup("< infile ls | cat > outfile");
    data = new_data();
    data->input = readline("bash-3.2.1$ ");
    add_history(data->input);
    lexer(data);
    t_list *cur = data->tokens;
    // list = lexer(data);
    // env_init(data, env);
    // get_envp(data);
    while (cur)
    {
        // printf("env : %s\n", cur->env);
        printf("cur : %d, %s\n", cur->token->type, cur->token->str);
        cur = cur->next;
    }
    // list = NULL;
    // data = new_data();
    // t_list *temp = data->envs;
    // env_init(data, env); 
    // get_envp(data);
    
    // while (temp)
    // {
    //     printf("origin data : %s\n", temp->env);
    //     temp = temp->next;
    // }
    // char *key = "USER";
    // // temp = data->envs;
    // del_envp(data, key);
    // temp  = data->envs;
    // while (temp)
    // {
    //     printf("data : %s\n", temp->env);
    //     temp = temp->next;
    // }

    // char *wonie = "wonie";
    // char *keyword = "wonie";
    // printf("%d\n", ft_strncmp(wonie, keyword, ft_strlen(keyword)));
    // // while (temp)
    // // {
    // //     printf("data : %s\n",  temp->env);
    // //     temp = temp->next;
    // // }

}


// t_list  *lexer(t_data *data)
// {
//     int i;

//     i = -1;
// }