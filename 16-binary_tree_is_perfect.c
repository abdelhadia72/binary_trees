#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Description: Checks if a binary tree is perfect.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (!tree || !tree->left || !tree->right)
		return (0);

	if (tree)
	{
		if (tree->left)
			left_height = 1 + binary_tree_is_perfect(tree->left);
		if (tree->right)
			right_height = 1 + binary_tree_is_perfect(tree->right);
		return ((left_height == right_height) ? 1 : 0);
	}

	return (0);
}
