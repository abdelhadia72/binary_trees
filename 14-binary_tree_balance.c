#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Description: Measures the height of a binary tree.
 * Return: Height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return (0);

    left_height = 1 + binary_tree_height(tree->left);
    right_height = 1 + binary_tree_height(tree->right);

    return (left_height > right_height) ? left_height : right_height;
}

int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (left_height - right_height);
}