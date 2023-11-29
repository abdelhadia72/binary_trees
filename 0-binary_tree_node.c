#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node for a binary tree.
 * @parent: Pointer to the parent node.
 * @value: Integer value to be stored in the new node.
 *
 * Return: Pointer to the newly created node on success, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent)
	{
		if (!parent->left)
			parent->left = new_node;
		else if (!parent->right)
			parent->right = new_node;
		else
			return (NULL);
	}

	return (new_node);
}
