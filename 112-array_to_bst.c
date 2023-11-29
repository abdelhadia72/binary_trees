#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return NULL;

	bst_t *root = binary_tree_node(NULL, array[0]);
	if (root == NULL)
		return NULL;

	for (size_t i = 1; i < size; i++)
	{
		if (bst_search(root, array[i]) == NULL)
		{
			if (bst_insert(root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}

	return root;
}

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return NULL;

	if (tree->n == value)
		return (bst_t *)tree;

	if (tree->n > value)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);
}
