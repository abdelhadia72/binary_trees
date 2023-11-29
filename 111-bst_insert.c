#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{

	if (!(*tree) || !tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
			return (binary_tree_node(*tree, value));
		return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
			return (binary_tree_node(*tree, value));
		return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}
