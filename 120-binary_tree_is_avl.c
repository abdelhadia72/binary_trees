#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not a valid AVL Tree, 0.
 *         Otherwise, 1.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_is_avl_height(tree->left);
	right_height = binary_tree_is_avl_height(tree->right);

	if (abs(left_height - right_height) <= 1 &&
		binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
int binary_tree_is_avl_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_is_avl_height(tree->left);
	right_height = binary_tree_is_avl_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
