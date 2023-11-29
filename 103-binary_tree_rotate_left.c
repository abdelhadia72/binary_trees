#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Pointer to the new root after the rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *old_root, *new_root, *old_node;

	old_root = tree;
	new_root = tree->right;
	if (tree->right->left)
	{
		old_node = tree->right->left;
	}
	else
	{
		old_node = NULL;
	}
	new_root->left = old_root;
	old_root->parent = new_root;
	old_root->right = old_node;

	if (old_node)
	{
		old_node->parent = old_root;
		old_node->left = NULL;
	}

	return (new_root);
}
