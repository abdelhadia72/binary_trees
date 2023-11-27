#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree.
 * Description: A leaf node is a node with no left or right child.
 * @node: Pointer to the node to check.
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);

	return (0);
}
