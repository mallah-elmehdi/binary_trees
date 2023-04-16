#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	const binary_tree_t *node1 = first, *node2 = second;

	if (!first || !second)
		return (NULL);

	while (node1 != node2)
	{
		if (node1->parent == node2->parent)
			ancestor = node1->parent;

		node1 = node1->parent ? node1->parent : second;
		node2 = node2->parent ? node2->parent : first;
	}

	return ((binary_tree_t *)ancestor);
}
