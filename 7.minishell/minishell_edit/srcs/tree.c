#include "../includes/minishell.h"

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

