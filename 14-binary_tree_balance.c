#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Description: Measures the balance factor of a binary tree.
 * Return: Balance factor of the tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree)
	{
		if (tree->left)
			left_height = 1 + binary_tree_balance(tree->left);

		if (tree->right)
			right_height = 1 + binary_tree_balance(tree->right);
	}
	else
	{
		return (0);
	}
	return (left_height - right_height);
}