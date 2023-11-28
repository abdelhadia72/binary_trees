#include "binary_trees.h"

/**
 * binary_tree_postorder - Prints the nodes of a binary tree in postorder.
 * @tree: Pointer to the root node of the tree.
 * @func: Prints value.
 *
 * Description: Prints the nodes of a binary tree in postorder.
 * Return: Nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

