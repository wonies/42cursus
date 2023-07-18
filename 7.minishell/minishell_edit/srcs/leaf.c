#include "../includes/minishell.h"

void init_leaf(t_data *data)
{
    t_leaf *cur_leaf;
    t_list *cur_token;
    t_leaf *new_leaf;

    cur_token = data->tokens;
    data->root = create_leaf(T_PIPE, NULL);
    data->root->left_child = create_leaf(T_CMD, NULL);
    cur_leaf = data->root->left_child;
    while (cur_token)
    {
        if (cur_token->token->type == T_PIPE)
        {
            new_leaf = create_leaf(T_PIPE, NULL);
            cur_leaf->right_child = new_leaf;
            new_leaf->left_child = cur_leaf;
            cur_leaf = new_leaf;
        }
        else if (cur_token->token->type == T_REDIRECT || cur_token->token->type == T_ARG)
        {
            new_leaf = create_leaf(cur_token->token->type, cur_token->token);
            cur_leaf->right_child = new_leaf;
            new_leaf->left_child = cur_leaf;
        }
        else if (cur_token->token->type == T_CMD)
        {
            new_leaf = create_leaf(T_CMD, cur_token->token);
            cur_leaf->right_child = new_leaf;
            new_leaf->left_child = cur_leaf;
            cur_leaf = new_leaf;
        }
        cur_token = cur_token->next;
    }
}

void print_tree(t_leaf *root, int level)
{
    if (root == NULL)
        return;

    printf("%*s", level * 4, ""); // 들여쓰기
    printf("|-- ");

    if (root->leaf_type == T_CMD || root->leaf_type == T_ARG || root->leaf_type == T_REDIRECT)
        printf("%s\n", root->token->str);
    else if (root->leaf_type == T_PIPE)
        printf("|\n");

    print_tree(root->left_child, level + 1);
    print_tree(root->right_child, level);
}


// void	init_leaf(t_data *data)
// {
// 	t_leaf	*cur_leaf;
// 	t_list	*cur_token;
// 	t_leaf	*new_leaf;

// 	cur_token = data->tokens;
// 	data->root = create_leaf(T_PIPE, NULL);
// 	data->root->left_child = create_leaf(T_CMD, NULL);
// 	cur_leaf = data->root->left_child;

// 	while (cur_token)
// 	{
// 		if (cur_token->token->type == T_PIPE)
// 		{
// 			new_leaf = create_leaf(T_PIPE, NULL);
// 			cur_leaf->right_child = new_leaf;
// 			new_leaf->left_child = cur_leaf;
// 			cur_leaf = new_leaf;
// 		}
// 		else if (cur_token->token->type == T_REDIRECT || cur_token->token->type == T_ARG)
// 		{
// 			new_leaf = create_leaf(cur_token->token->type, cur_token->token);
// 			cur_leaf->right_child = new_leaf;
// 			new_leaf->left_child = cur_leaf;
// 		}
// 		else if (cur_token->token->type == T_CMD)
// 		{
// 			new_leaf = create_leaf(T_CMD, cur_token->token);
// 			cur_leaf->right_child = new_leaf;
// 			new_leaf->left_child = cur_leaf;
// 			cur_leaf = new_leaf;
// 		}
// 		cur_token = cur_token->next;
// 	}

// }

// void print_tree(t_leaf *root, int level)
// {
//     if (root == NULL)
//         return;

//     printf("%*s", level * 4, ""); // 들여쓰기
//     printf("|-- ");

//     if (root->leaf_type == T_CMD || root->leaf_type == T_ARG || root->leaf_type == T_REDIRECT || root->leaf_type == T_PIPE)
//         printf("%s\n", root->token->str);
//     else if (root->leaf_type == T_PIPE)
//         printf("|\n");

//     print_tree(root->left_child, level + 1);
//     print_tree(root->right_child, level);
// }