#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent = NULL, *successor = NULL;

	while (node != NULL)
	{
		if (node->n == value)
		{
			/* No children or right-child only */
			if (node->left == NULL)
			{
				if (parent != NULL && parent->left == node)
					parent->left = node->right;
				else if (parent != NULL)
					parent->right = node->right;
				if (node->right != NULL)
					node->right->parent = parent;
				free(node);
				return (parent == NULL ? node->right : root);
			}

			/* Left-child only */
			if (node->right == NULL)
			{
				if (parent != NULL && parent->left == node)
					parent->left = node->left;
				else if (parent != NULL)
					parent->right = node->left;
				node->left->parent = parent;
				free(node);
				return (parent == NULL ? node->left : root);
			}

			/* Two children */
			successor = inorder_successor(node->right);
			node->n = successor->n;
			value = successor->n;
			parent = node;
			node = node->right;
		}
		else if (node->n > value)
		{
			parent = node;
			node = node->left;
		}
		else
		{
			parent = node;
			node = node->right;
		}
	}

	return (root);
}
