#include "binary_trees.h"

int avl_height(const avl_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return 0;

	left_height = avl_height(tree->left);
	right_height = avl_height(tree->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

avl_t *avl_balancer(avl_t **tree)
{
	int balance_factor = binary_tree_balance(*tree);

	if (balance_factor >= 1)
	{
		if (binary_tree_balance((*tree)->left) >= 0)
		{
			*tree = binary_tree_rotate_right(*tree);
		}
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	else if (balance_factor <= -1)
	{
		if (binary_tree_balance((*tree)->right) <= -1)
		{
			*tree = binary_tree_rotate_left(*tree);
		}
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return *tree;
}

avl_t *insert_node(avl_t **tree, int value)
{
	avl_t *new_node = NULL, *current = (*tree);

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

avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	int balance_factor = binary_tree_balance(*tree);

	if (balance_factor > 1 || balance_factor < -1)
	{
		*tree = avl_balancer(tree);
	}

	avl_t *new_node = insert_node(tree, value);

	if (!new_node)
		return (NULL);

	if (balance_factor > 1 || balance_factor < -1)
	{
		*tree = avl_balancer(tree);
	}

	return new_node;
}
