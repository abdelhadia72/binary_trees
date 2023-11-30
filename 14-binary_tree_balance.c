#include "binary_trees.h"

int get_height(const binary_tree_t *tree);

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
		left_height = get_height(tree->left);
		right_height = get_height(tree->right);
	}
	else
	{
		return (0);
	}
	return (left_height - right_height);
}

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
