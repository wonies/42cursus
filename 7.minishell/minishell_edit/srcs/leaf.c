#include "../includes/minishell.h"

// void init_leaf(t_data *data)
// {
//     t_leaf *cur_leaf;
//     t_list *cur_token;
//     t_leaf *new_leaf;

// 	if (!data->tokens)
// 		return ;
//     cur_token = data->tokens;
//     data->root = create_leaf(T_PIPE, NULL);
//     data->root->left_child = create_leaf(T_CMD, NULL);
//     cur_leaf = data->root->left_child;
//     while (cur_token)
//     {
// 		if (!cur_token)
// 			break ;
// 		while (cur_token && cur_token->token->type != T_PIPE)
// 		{
// 			tree_left_right(cur_leaf, cur_token);
// 			cur_token = cur_token->next;
// 		}
// 		if (cur_token->token->type == T_PIPE)
// 			tree_leaf(&cur_leaf);
//         cur_token = cur_token->next;
//     }
// }

// void	tree_leaf(t_leaf **cur_leaf)
// {
// 	*cur_leaf = (*cur_leaf)->parent;
// 	(*cur_leaf)->exist = TRUE;
// 	(*cur_leaf)->right_child = create_leaf(T_PIPE, *cur_leaf);
// 	*cur_leaf = (*cur_leaf)->right_child;
// 	(*cur_leaf)->left_child = create_leaf(T_CMD, *cur_leaf);
// 	*cur_leaf = (*cur_leaf)->left_child;
// }


// void	tree_left_right(t_leaf *cur_leaf, t_list *cur_token)
// {
// 	if (cur_token->token->type == T_REDIRECT)
// 		tree_add_left(cur_leaf, cur_token->token, T_REDIRECT);
// 	else if (cur_token->token->type == T_CMD)
// 		tree_add_right(cur_leaf, cur_token->token, T_CMD);
// 	else if (cur_token->token->type == T_ARG)
// 	{
// 		if (cur_token->pre->token->type == T_REDIRECT)
// 			tree_add_left(cur_leaf, cur_token->token, T_ARG);
// 		else if (cur_token->pre->token->type == T_CMD \
// 			|| cur_token->pre->token->type == T_ARG)
// 			tree_add_right(cur_leaf, cur_token->token, T_ARG);
// 	}
// }


// t_bool	tree_add_left(t_leaf *parent, t_token *new_token, int leaf_type)
// {
// 	t_leaf	*child;

// 	if (!parent || !new_token)
// 		return (FALSE);
// 	while (parent->left_child)
// 		parent = parent->left_child;
// 	child = create_leaf(leaf_type, parent);
// 	child->token = new_token;
// 	parent->left_child = child;
// 	return (TRUE);
// }

// t_bool	tree_add_right(t_leaf *parent, t_token *new_token, int leaf_type)
// {
// 	t_leaf	*child;

// 	if (!parent || !new_token)
// 		return (FALSE);
// 	while (parent->right_child)
// 		parent = parent->right_child;
// 	child = create_leaf(leaf_type, parent);
// 	child->token = new_token;
// 	parent->right_child = child;
// 	return (TRUE);
// }


t_leaf	*create_leaf(int leaf_type, t_leaf *parent)
{
	t_leaf	*new_leaf = (t_leaf *)ft_calloc(1, sizeof(t_leaf));
	if (!new_leaf)
		return (NULL);
	new_leaf->parent = parent;
	new_leaf->left_child = NULL;
	new_leaf->right_child = NULL;
	new_leaf->leaf_type = leaf_type;

	return (new_leaf);
}



void	init_leaf(t_data *data)
{
	t_leaf *cur_leaf;
	t_list *cur_token;

	cur_token = data->tokens;
	if (!cur_token)
		return ;
	data->root = create_leaf(T_PIPE, NULL);
	data->root->left_child = create_leaf(T_CMD, data->root);
	cur_leaf = data->root->left_child;
	while (cur_token)
	{
		while (cur_token && cur_token->token->type != T_PIPE)
		{
			tree_left_right(cur_leaf, cur_token);
			cur_token = cur_token->next;
		}
		if (!cur_token)
			break ;
		if (cur_token && cur_token->token->type == T_PIPE)
			create_pipe(&cur_leaf);
		cur_token = cur_token->next;
	}	
}


void	create_pipe(t_leaf **cur)
{
	*cur = (*cur)->parent;
	(*cur)->exist = 1;
	(*cur)->leaf_type = T_PIPE;
	(*cur)->right_child = create_leaf(T_PIPE, *cur);
	*cur = (*cur)->right_child;
	(*cur)->left_child = create_leaf(T_CMD, *cur);
	*cur = (*cur)->left_child;
}

// void init_leaf(t_data *data)
// {
//     t_leaf *cur_leaf;
//     t_list *cur_token;

//     cur_token = data->tokens;
//     if (!cur_token)
//         return;
//     data->root = create_leaf(T_PIPE, NULL);
//     data->root->left_child = create_leaf(T_CMD, data->root);
//     cur_leaf = data->root->left_child;
//     while (cur_token)
//     {
// 		while (cur_token && cur_token->token->type != T_PIPE)
//         {
//             tree_left_right(cur_leaf, cur_token);
//             cur_token = cur_token->next;
//         }
//         if (!cur_token)
//             return ;
//         if (cur_token && cur_token->token->type == T_PIPE)
//             tree_leaf(&cur_leaf);
// 		if (cur_token)
// 			cur_token = cur_token->next;
//     }
// }

// void tree_leaf(t_leaf **cur_leaf)
// {
//     *cur_leaf = (*cur_leaf)->parent;
//     (*cur_leaf)->exist = TRUE;
//     (*cur_leaf)->right_child = create_leaf(T_PIPE, *cur_leaf);
//     *cur_leaf = (*cur_leaf)->right_child;
//     (*cur_leaf)->left_child = create_leaf(T_CMD, *cur_leaf);
//     *cur_leaf = (*cur_leaf)->left_child;
// }

void tree_left_right(t_leaf *cur_leaf, t_list *cur_token)
{
    if (cur_token->token->type == T_REDIRECT)
        tree_add_left(cur_leaf, cur_token->token, T_REDIRECT);
    else if (cur_token->token->type == T_CMD)
        tree_add_right(cur_leaf, cur_token->token, T_CMD);
    else if (cur_token->token->type == T_ARG)
    {
        if (cur_token->pre && cur_token->pre->token->type == T_REDIRECT)
            tree_add_left(cur_leaf, cur_token->token, T_ARG);
        else if (cur_token->pre && cur_token->pre->token->type == T_CMD
                 || cur_token->pre && cur_token->pre->token->type == T_ARG)
            tree_add_right(cur_leaf, cur_token->token, T_ARG);
    }
}

t_bool tree_add_left(t_leaf *parent, t_token *new_token, int leaf_type)
{
    t_leaf *child;

    if (!parent || !new_token)
        return (FALSE);
    while (parent->left_child)
        parent = parent->left_child;
    child = create_leaf(leaf_type, parent);
    child->token = new_token;
    parent->left_child = child;
    return (TRUE);
}

t_bool tree_add_right(t_leaf *parent, t_token *new_token, int leaf_type)
{
    t_leaf *child;

    if (!parent || !new_token)
        return (FALSE);
    while (parent->right_child)
        parent = parent->right_child;
    child = create_leaf(leaf_type, parent);
    child->token = new_token;
    parent->right_child = child;
    return (TRUE);
}


// void init_leaf(t_data *data)
// {
// 	t_leaf *cur_leaf;
// 	t_list *cur_token;
// 	t_leaf *new_leaf;

// 	if (!data->tokens)
// 		return;
// 	cur_token = data->tokens;
// 	data->root = create_leaf(T_PIPE, NULL);
// 	data->root->left_child = create_leaf(T_CMD, NULL);
// 	cur_leaf = data->root->left_child;
// 	while (cur_token)
// 	{
// 		while (cur_token && cur_token->token->type != T_PIPE)
// 		{
// 			tree_left_right(cur_leaf, cur_token);
// 			cur_token = cur_token->next;
// 		}
// 		if (!cur_token)
// 			break;
// 		if (cur_token && cur_token->token->type == T_PIPE)
// 			cur_leaf = tree_leaf(&cur_leaf);
// 		// if (cur_token)
// 			cur_token = cur_token->next;
// 	}
// }

// t_leaf *tree_leaf(t_leaf **cur_leaf)
// {
// 	t_leaf *pipe_node = create_leaf(T_PIPE, (*cur_leaf)->parent);
// 	(*cur_leaf)->parent->right_child = pipe_node;
// 	*cur_leaf = pipe_node;

// 	t_leaf *cmd_node = create_leaf(T_CMD, *cur_leaf);
// 	(*cur_leaf)->left_child = cmd_node;
// 	*cur_leaf = cmd_node;

// 	return cmd_node;
// }

// void tree_left_right(t_leaf *cur_leaf, t_list *cur_token)
// {
// 	if (cur_token->token->type == T_REDIRECT)
// 		tree_add_left(cur_leaf, cur_token->token, T_REDIRECT);
// 	else if (cur_token->token->type == T_CMD)
// 		tree_add_right(cur_leaf, cur_token->token, T_CMD);
// 	else if (cur_token->token->type == T_ARG)
// 	{
// 		if (cur_token->pre && cur_token->pre->token->type == T_REDIRECT)
// 			tree_add_left(cur_leaf, cur_token->token, T_ARG);
// 		else if (cur_token->pre && cur_token->pre->token->type == T_CMD
// 			|| cur_token->pre && cur_token->pre->token->type == T_ARG)
// 			tree_add_right(cur_leaf, cur_token->token, T_ARG);
// 	}
// }

// t_bool tree_add_left(t_leaf *parent, t_token *new_token, int leaf_type)
// {
// 	t_leaf *child;

// 	if (!parent || !new_token)
// 		return (FALSE);
// 	while (parent->left_child)
// 		parent = parent->left_child;
// 	child = create_leaf(leaf_type, parent);
// 	child->token = new_token;
// 	parent->left_child = child;
// 	return (TRUE);
// }

// t_bool tree_add_right(t_leaf *parent, t_token *new_token, int leaf_type)
// {
// 	t_leaf *child;

// 	if (!parent || !new_token)
// 		return (FALSE);
// 	while (parent->right_child)
// 		parent = parent->right_child;
// 	child = create_leaf(leaf_type, parent);
// 	child->token = new_token;
// 	parent->right_child = child;
// 	return (TRUE);
// }




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