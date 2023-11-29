#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree)
        return (NULL);

    if (tree->n == value)
        return ((bst_t *)tree);

    if (tree->n >= value)
        return (bst_search(tree->left, value));

    return (bst_search(tree->right, value));
}