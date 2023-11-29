#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value
 */

bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return (0);
    
    if (root->n == value)
    {
        if (root->right || root->left)
        {
            root->right->parent = root->parent;
            root->left->parent = root->right;
        }
        if (root->parent)
        {
            bst_t *parnt = root->parent;
        }
        free(root);
        return (parnt);
    }
    /* Check left*/
    if (root->n > value)
    {
        if (!root->left)
            return 0;
        bst_remove(root->left, value);
    }
    /*Check right*/
    if (root->n < value)
    {
        if (!root->right)
            return 0;
        bst_remove(root->right, value);
    }
}