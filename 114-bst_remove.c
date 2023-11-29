#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return NULL;

	if (root->n == value)
	{
		bst_t *new_root = NULL;

		if (root->right && root->left)
		{
			bst_t *successor = root->right;

			while (successor->left)
				successor = successor->left;

			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
		else if (root->right)
		{
			new_root = root->right;
			new_root->parent = root->parent;
			free(root);
		}
		else if (root->left)
		{
			new_root = root->left;
			new_root->parent = root->parent;
			free(root);
		}
		else
		{
			free(root);
		}

		return new_root;
	}

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		root->right = bst_remove(root->right, value);

	return root;
}
