#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes in a binary tree with at least one child.
 * @tree: Pointer to the root of the tree.
 *
 * Return: Number of nodes with at least one child, 0 if @tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t left_nodes = binary_tree_nodes(tree->left);
    size_t right_nodes = binary_tree_nodes(tree->right);

    if (tree->left || tree->right)
        return (left_nodes + right_nodes + 1);

    return (left_nodes + right_nodes);
}