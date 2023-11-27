#include "binary_trees.h"

/**
 * binary_tree_inorder - Prints the nodes of a binary tree in inorder.
 * @tree: Pointer to the root node of the tree.
 * @func: prints value
 * Description: Prints the nodes of a binary tree in inorder.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (!tree->right && !tree->left)
	{
		return;
	}
	binary_tree_preorder(tree->left, func);
    func(tree->n);
	binary_tree_preorder(tree->right, func);
}