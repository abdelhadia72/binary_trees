#include "binary_trees.h"
#include <limits.h>

/* Functions */
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_insert_helper(avl_t **tree, avl_t *new_node);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_rotate_left(avl_t *node);
avl_t *avl_rotate_right(avl_t *node);
int avl_balance_factor(avl_t *node);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in @array
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;

    if (!array || size < 1)
        return (NULL);

    root = array_to_avl(array, size);
    return (root);
}

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in @array
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (!array || size < 1)
        return (NULL);

    for (i = 0; i < size; i++)
        avl_insert(&root, array[i]);

    return (root);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (!tree)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*tree)
    {
        *tree = new_node;
        return (new_node);
    }

    return (avl_insert_helper(tree, new_node));
}

/**
 * avl_insert_helper - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree for inserting the value
 * @new_node: A pointer to the new node to insert
 * Return: A pointer to the created node, or NULL on failure
 */

avl_t *avl_insert_helper(avl_t **tree, avl_t *new_node)
{
    avl_t *parent = NULL;

    if (!tree || !new_node)
        return (NULL);

    parent = *tree;
    while (parent)
    {
        if (new_node->n == parent->n)
        {
            free(new_node);
            return (NULL);
        }
        if (new_node->n < parent->n)
        {
            if (!parent->left)
            {
                parent->left = new_node;
                new_node->parent = parent;
                return (new_node);
            }
            parent = parent->left;
        }
        else
        {
            if (!parent->right)
            {
                parent->right = new_node;
                new_node->parent = parent;
                return (new_node);
            }
            parent = parent->right;
        }
    }
    return (NULL);
}

/**
 * avl_rotate_left - Performs a left rotation on an AVL tree node
 * @node: The node to rotate
 * Return: The new root of the subtree after rotation
 */

avl_t *avl_rotate_left(avl_t *node)
{
    avl_t *pivot = node->right;

    node->right = pivot->left;
    if (pivot->left)
        pivot->left->parent = node;

    pivot->left = node;
    pivot->parent = node->parent;
    node->parent = pivot;

    return pivot;
}

/**
 * avl_rotate_right - Performs a right rotation on an AVL tree node
 * @node: The node to rotate
 * Return: The new root of the subtree after rotation
 */

avl_t *avl_rotate_right(avl_t *node)
{
    avl_t *pivot = node->left;

    node->left = pivot->right;
    if (pivot->right)
        pivot->right->parent = node;

    pivot->right = node;
    pivot->parent = node->parent;
    node->parent = pivot;

    return pivot;
}

/**
 * avl_balance_factor - Calculates the balance factor of an AVL tree node
 * @node: The node to calculate the balance factor for
 * Return: The balance factor of the node
 */

int avl_balance_factor(avl_t *node)
{
    int left_height = 0, right_height = 0;

    if (node->left)
        left_height = binary_tree_height(node->left);
    if (node->right)
        right_height = binary_tree_height(node->right);

    return (left_height - right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: The height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (!tree || (!tree->left && !tree->right))
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height >= right_height)
        return (left_height + 1);
    return (right_height + 1);
}
