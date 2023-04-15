#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node has no sibling
 *         or if node or parent are NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return its right sibling */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return its left sibling */
	if (node->parent->right == node)
		return (node->parent->left);

	/* If node is the root, or something went wrong, return NULL */
	return (NULL);
}
