#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root, *temp;
    root = binary_tree_node(NULL, array[0]);

    while (size)
    {
        
        binary_tree_node(tree,array[size])
    }
}