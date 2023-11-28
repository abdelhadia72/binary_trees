#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Description: Finds the lowest common ancestor of two nodes.
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	binary_tree_t *stepdad, *sugadaddy;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	stepdad = first->parent, sugadaddy = second->parent;
	if (first == sugadaddy || !stepdad || (!stepdad->parent && sugadaddy))
		return (binary_trees_ancestor(first, sugadaddy));
	else if (stepdad == second || !sugadaddy || (!sugadaddy->parent && stepdad))
		return (binary_trees_ancestor(stepdad, second));
	return (binary_trees_ancestor(stepdad, sugadaddy));
}
