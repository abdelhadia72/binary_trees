#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_node;

	old_root = tree;
	new_root = tree->left;
	old_node = tree->left->right;

	new_root->left = old_root;
	old_root->parent = new_root;
	if (old_node->right)
	{
		old_node->right = old_node;
		old_node->parent = new_root->left;
	}

	return (new_root);
}
