#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: If tree is a valid Max Binary Heap, 1, otherwise, 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	if (tree->left && tree->n < tree->left->n)
		return 0;

	if (tree->right && tree->n < tree->right->n)
		return 0;

	if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
		return 0;

	return 1;
}
