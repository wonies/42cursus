#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/minishell.h"

typedef struct s_treeNode
{
    struct s_treeNode *parent;
    struct s_treeNode *left_child;
    struct s_treeNode *right_child;
    int is_pipe;
    int leaf_type;
    char *data;
} TreeNode;

TreeNode *create_node(int leaf_type, char *data)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->parent = NULL;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    new_node->is_pipe = 0;
    new_node->leaf_type = leaf_type;
    new_node->data = strdup(data);

    return new_node;
}

void add_child(TreeNode *parent, TreeNode *child, int is_left)
{
    child->parent = parent;
    if (is_left)
        parent->left_child = child;
    else
        parent->right_child = child;
}

void printfs_tree(TreeNode *root, int level)
{
    if (root == NULL)
        return;

    printf("%*s", level * 4, ""); // 들여쓰기

    if (root->is_pipe)
        printf("|-- PIPE\n");
    else if (root->leaf_type == T_CMD)
        printf("|-- CMD: %s\n", root->data);
    else if (root->leaf_type == T_ARG)
        printf("|-- ARG: %s\n", root->data);
    else if (root->leaf_type == T_REDIRECT)
        printf("|-- REDIRECT\n");

    printfs_tree(root->left_child, level + 1);
    printfs_tree(root->right_child, level);
}

int main()
{
    TreeNode *root = create_node(T_PIPE, NULL);
    TreeNode *cmd1 = create_node(T_CMD, "echo");
    TreeNode *arg1 = create_node(T_ARG, "hello");
    TreeNode *pipe_node = create_node(T_PIPE, NULL);
    TreeNode *cmd2 = create_node(T_CMD, "echo");
    TreeNode *redirect_node = create_node(T_REDIRECT, NULL);
    TreeNode *arg2 = create_node(T_ARG, "b");

    add_child(root, cmd1, 1);
    add_child(cmd1, arg1, 0);
    add_child(root, pipe_node, 0);
    add_child(pipe_node, cmd2, 1);
    add_child(cmd2, redirect_node, 1);
    add_child(redirect_node, arg2, 0);

    printfs_tree(root, 0);

    return 0;
}
// #include "../includes/minishell.h"


// TreeNode *create_node(int leaf_type, t_leaf *parent)
// {
//     TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
//     new_node->parent = parent;
// 	new_node->left_child = NULL;
//     new_node->right_child = NULL;
// 	new_node->leaf_type = leaf_type;
    
// 	return new_node;
// }

// void build_tree(t_data *data, TreeNode **root)
// {
//     t_list *cur_token = data->tokens;
//     TreeNode *cur_node = NULL;
//     TreeNode *prev_node = NULL;
//     TreeNode *pipe_node = NULL;

//     while (cur_token)
//     {
//         if (cur_token->token->type == T_PIPE)
//         {
//             pipe_node = create_node(T_PIPE, prev_node);
//             if (prev_node == NULL)
//                 *root = pipe_node;
//             else
//                 prev_node->right_child = pipe_node;
//             cur_node = NULL;
//         }
//         else if (cur_token->token->type == T_CMD || cur_token->token->type == T_ARG)
//         {
//             TreeNode *new_node = create_node(cur_token->token->type, prev_node);
//             new_node->data = strdup(cur_token->token->str);
//             if (cur_node == NULL)
//             {
//                 cur_node = new_node;
//                 if (pipe_node)
//                     pipe_node->left_child = cur_node;
//                 else
//                     *root = cur_node;
//             }
//             else
//             {
//                 cur_node->right_child = new_node;
//                 cur_node = new_node;
//             }
//         }
//         else if (cur_token->token->type == T_REDIRECT)
//         {
//             TreeNode *new_node = create_node(T_REDIRECT, prev_node);
//             if (cur_node)
//                 cur_node->left_child = new_node;
//         }

//         prev_node = cur_node;
//         cur_token = cur_token->next;
//     }
// }

// void print_tree(TreeNode *root, int level)
// {
//     if (root == NULL)
//         return;

//     printf("%*s", level * 4, ""); // 들여쓰기

//     if (root->is_pipe)
//         printf("|-- PIPE\n");
//     else if (root->leaf_type == T_CMD)
//         printf("|-- CMD: %s\n", root->data);
//     else if (root->leaf_type == T_ARG)
//         printf("|-- ARG: %s\n", root->data);
//     else if (root->leaf_type == T_REDIRECT)
//         printf("|-- REDIRECT\n");

//     print_tree(root->left_child, level + 1);
//     print_tree(root->right_child, level);
// }


// int main()
// {
//     t_data data;
//     // 데이터 초기화 및 토큰화 작업 수행

//     TreeNode *root = NULL;
//     build_tree(&data, &root);
//     printf_tree(root, 0, 0);

//     return 0;
// }
