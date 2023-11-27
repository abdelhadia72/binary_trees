#include "binary_trees.h"

/**
 * binary_tree_preorder - Prints the nodes of a binary tree in preorder.
  * @tree: Pointer to the root node of the tree.
  * @func: prints value
  * Description: Prints the nodes of a binary tree in preorder.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	func(tree->n);
	if (!tree || !func)
		return;
	if (!tree->right && !tree->left)
	{
		return;
	}
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
