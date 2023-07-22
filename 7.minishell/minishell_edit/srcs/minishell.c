#include "../includes/minishell.h"



void print_tree_recursive(t_leaf *node, int level)
{
    if (!node)
        return;

    for (int i = 0; i < level - 1; i++)
        printf("|     "); // 들여쓰기

    if (level > 0)
        printf("|-- ");

    if (node->token)
    {
        if (node->token->type == T_CMD)
            printf("CMD: %s\n", node->token->str);
        else if (node->token->type == T_ARG)
            printf("ARG: %s\n", node->token->str);
        else if (node->token->type == T_REDIRECT)
        {
            printf("REDIRECT");
            if (node->token->re_type == T_INPUT)
                printf(" (type: <)\n");
            else if (node->token->re_type == T_OUTPUT)
                printf(" (type: >)\n");
            else if (node->token->re_type == T_HEREDOC)
                printf(" (type: <<)\n");
            else if (node->token->re_type == T_APPEND)
                printf(" (type: >>)\n");
        }
    }
    else
    {
        if (node->leaf_type == T_PIPE)
            printf("PIPE\n");
        else if (node->leaf_type == T_CMD)
            printf("CMD\n");
        else if (node->leaf_type == T_ARG)
            printf("ARG\n");
        else if (node->leaf_type == T_REDIRECT)
            printf("REDIRECT\n");
        else
            printf("UNKNOWN\n");
    }

    print_tree_recursive(node->left_child, level + 1);
    print_tree_recursive(node->right_child, level + 1);
}

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
    env_init(data, env);
    get_envp(data);
    lexer(data);
    t_list *cur = data->tokens;
    syntax(data);
    init_leaf(data);
    // t_leaf *root;
    // root = leaf_init(data);
    print_tree_recursive(data->root, 0);
    // print_tree_inorder(data->root);
    // TreeNode *root = NULL;
    // build_tree(data, &root);
    // prints_tree(data->root, 0, 0);
    // list = lexer(data);
    // env_init(data, env);
    // get_envp(data);
    // print_tree(root);
    while (cur)
    {
        // printf("env : %s\n", cur->env);
        printf("cur : %d, %d, {%s}, {%p}\n", cur->token->type, cur->token->re_type ,cur->token->str, cur->token);
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