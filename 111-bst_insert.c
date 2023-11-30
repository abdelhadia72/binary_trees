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
	bst_t *new_node = NULL, *current = (*tree);

	if (tree == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	while (1)
	{
		if (value == current->n)
		{
			free(new_node);
			return (NULL);
		}
		else if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->right;
		}
	}
}
