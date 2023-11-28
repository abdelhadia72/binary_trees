#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 * traversal.
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to a function to call for each node.
 *
 * Description: Traverses a binary tree using level-order traversal.
 * Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->parent == NULL)
		func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	if (tree->left)
		binary_tree_levelorder(tree->left, func);
	if (tree->right)
		binary_tree_levelorder(tree->right, func);
}
