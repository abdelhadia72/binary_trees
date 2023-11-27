#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root of the tree.
 *
 * Description: This function recursively deletes all nodes in the binary tree
 * starting from the leaves and moving towards the root.
 */

void binary_tree_delete(binary_tree_t *tree)
{

	if (tree)
	{
		if (!tree)
			return;
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);

		free(tree);
	}
}
