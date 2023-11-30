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
	if (tree)
	{
		int left_height = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
		int right_height = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
		return (left_height - right_height);
	}

	return (0);
}
