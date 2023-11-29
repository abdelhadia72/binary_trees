#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{

    if (!tree)
        return (NULL);

    if (!(*tree))
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    /* go left */
    if ((*tree)->n > value)
    {
        if (!(*tree)->left)
            return (binary_tree_node((*tree), value));
        else
            return (bst_insert(&((*tree)->left), value));
    }
    /* go right */
    else if ((*tree)->n < value)
    {
        if (!(*tree)->right)
            return (binary_tree_node((*tree), value));
        else
            return (bst_insert(&((*tree)->right), value));
    }

    return (NULL);
}