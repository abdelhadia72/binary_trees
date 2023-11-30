#include "binary_trees.h"

/**
 * get_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
int get_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = 1 + get_height(tree->left);
		int right_height = 1 + get_height(tree->right);

		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Description: Checks if a binary tree is perfect.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = get_height(tree->left);
		int right_height = get_height(tree->right);
		return (left_height == right_height);
	}

	return (0);
}
