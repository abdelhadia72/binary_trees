#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new left child in a binary tree.
 * @parent: Pointer to the parent node.
 * @value: Integer value to be stored in the new node.
 *
 * Return: Pointer to the newly created node on success, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent)
	{
		if (!parent->left)
			parent->left = new_node;
		else
		{
			new_node->left = parent->left;
			parent->left->parent = new_node;
			parent->left = new_node;
		}
	}

	return (new_node);
}
