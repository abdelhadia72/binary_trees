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
	old_node = tree->right->left;

	new_root->left = old_root;
	old_root->parent = new_root;
	old_root->right = old_node;
	old_node->parent = old_root;

	return (new_root);
}
