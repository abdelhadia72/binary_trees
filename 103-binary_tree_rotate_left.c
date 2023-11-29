#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_left;

	new_root = tree->left;
	old_root = tree;
	old_left = tree->left->right;

	new_root->right = old_root;
	new_root->left->right = old_left;

	return (new_root);
}