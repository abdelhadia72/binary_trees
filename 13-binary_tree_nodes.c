#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes in a
 * binary tree with at least one child.
 * @tree: Pointer to the root of the tree.
 *
 * Return: Number of nodes with at least one child, 0 if @tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			nodes++;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
