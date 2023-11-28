#include "binary_trees.h"

/**
 * binary_tree_preorder - Prints the nodes of a binary tree in preorder.
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to a function to call for each node.
 *
 * Description: Prints the nodes of a binary tree in preorder.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
