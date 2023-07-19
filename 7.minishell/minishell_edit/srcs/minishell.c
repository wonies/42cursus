#include "../includes/minishell.h"


void print_tree_inorder(t_leaf *node)
{
    if (node == NULL)
        return;

    print_tree_inorder(node->left_child);

    switch (node->leaf_type)
    {
        case T_PIPE:
            printf("PIPE\n");
            break;
        case T_CMD:
            printf("CMD: %s\n", node->token->str);
            break;
        case T_ARG:
            printf("ARG: %s\n", node->token->str);
            break;
        case T_REDIRECT:
            printf("REDIRECT\n");
            break;
        default:
            printf("UNKNOWN\n");
            break;
    }

    print_tree_inorder(node->right_child);
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
        printf("cur : %d, %d, %s\n", cur->token->type, cur->token->re_type ,cur->token->str);
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