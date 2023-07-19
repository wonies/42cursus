#include "../includes/minishell.h"

t_leaf *leaf_create(int leaf_type, t_leaf *parent)
{
	t_leaf *new = (t_leaf *)ft_calloc(1, sizeof(t_leaf));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->leaf_type = leaf_type;
	new->left_child = NULL;
	new->right_child = NULL;

	return (new);
}

t_leaf 	*leaf_init(t_data *data)
{
	t_leaf *cur_leaf;
	t_list *cur_token;

	cur_token = data->tokens;
	if (!cur_token)
		return NULL;
	cur_leaf = build_tree(&cur_token);
	return (cur_leaf);
}

t_leaf *build_tree(t_list **cur_token)
{
    if (*cur_token == NULL)
        return NULL;

    t_leaf *cur_leaf = NULL;

    if ((*cur_token)->token->type == T_PIPE) {
        (*cur_token) = (*cur_token)->next;
        cur_leaf = leaf_create(T_PIPE, NULL);
        cur_leaf->left_child = build_tree(cur_token);
        cur_leaf->right_child = build_tree(cur_token);
    } else if ((*cur_token)->token->type == T_CMD || (*cur_token)->token->type == T_ARG) {
        t_leaf* new_leaf = leaf_create((*cur_token)->token->type, NULL);
        cur_leaf = new_leaf;
    } else if ((*cur_token)->token->type == T_REDIRECT) {
        t_leaf* new_leaf = leaf_create(T_REDIRECT, NULL);
        (*cur_token) = (*cur_token)->next;
        cur_leaf = new_leaf;
        cur_leaf->left_child = build_tree(cur_token);
    }

    return cur_leaf;
}

// void print_tree_recursive(t_leaf *node, int level)
// {
//     if (node == NULL)
//         return;

//     for (int i = 0; i < level; i++)
//         printf("|   "); // 들여쓰기

//     if (node->leaf_type == T_PIPE)
//         printf("PIPE\n");
//     else if (node->leaf_type == T_CMD)
//         printf("CMD: %s\n", node->token->str);
//     else if (node->leaf_type == T_ARG)
//         printf("ARG: %s\n", node->token->str);
//     else if (node->leaf_type == T_REDIRECT)
//         printf("REDIRECT\n");
//     else
//         printf("UNKNOWN\n");

//     print_tree_recursive(node->left_child, level + 1);
//     print_tree_recursive(node->right_child, level); // 수정된 부분: level + 1 -> level
// }
// void print_tree(t_leaf *root)
// {
//     printf("Root\n");
//     print_tree_recursive(root, 0);
// }



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

// void print_tree_recursive(t_leaf *node, int level)
// {
//     if (!node)
//         return;

//     for (int i = 0; i < level; i++)
//         printf("   "); // 들여쓰기
	

// 	if (node->token)
// 	{
// 		if (node->token->type == T_CMD)
// 			printf("|		\n%s\n", node->token->str);
// 		else if (node->token->type == T_ARG)
// 			printf("|		\n%sn", node->token->str);
// 		else if (node->token->type == T_REDIRECT)
// 		{
// 			printf("REDIRECT && ");
// 			if (node->token->re_type == T_INPUT)
// 				printf("type :: < \n");
// 			else if (node->token->re_type == T_OUTPUT)
// 				printf("type: >\n");
// 			else if (node->token->re_type == T_HEREDOC)
// 				printf("type: <<\n");
// 			else if (node->token->re_type == T_APPEND)
// 				printf("type: >>\n");
// 		}
// 	}
// 	else
// 	{
// 		if (node->leaf_type == T_PIPE)
// 			printf("-- pipe --- \n");
// 		else
// 			printf("-- cmd  --- \n");
// 	}
//     print_tree_recursive(node->left_child, level + 1);
//     print_tree_recursive(node->right_child, level);
// }


// void prints_tree(t_leaf *root, int level, int is_left)
// {
// 	if (root == NULL)
// 		return;

// 	printf("%*s", level * 4, ""); // 들여쓰기

// 	if (is_left)
// 		printf("|-- L: ");
// 	else
// 		printf("|-- R: ");

// 	if (root->token != NULL)
// 	{
// 		if (root->token->type == T_CMD)
// 			printf("CMD: %s\n", root->token->str);
// 		else if (root->token->type == T_ARG)
// 			printf("ARG: %s\n", root->token->str);
// 		else if (root->token->type == T_REDIRECT)
// 			printf("REDIRECT: %s\n", root->token->str);
// 	}

// 	prints_tree(root->left_child, level + 1, 1);
// 	prints_tree(root->right_child, level + 1, 0);
// }
