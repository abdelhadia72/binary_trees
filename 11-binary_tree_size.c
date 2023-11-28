#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root of the tree.
 *
 * Return: Size of the binary tree, 0 if @tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t totalsize = 0;

	if (!tree)
		return (0);

	totalsize += binary_tree_size(tree->left);
	totalsize += binary_tree_size(tree->right);
	totalsize++;

	return (totalsize);
}
