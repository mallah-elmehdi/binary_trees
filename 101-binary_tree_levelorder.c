#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: Goes through a binary tree using level-order traversal and
 * calls the provided function for each visited node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* Create a queue to store nodes to be visited */
	binary_tree_t *queue[10000];
	int front = 0, rear = 0;

	/* Add root node to queue */
	queue[rear++] = (binary_tree_t *)tree;

	/* Traverse tree level by level */
	while (front < rear)
	{
		/* Get the next node to visit from the queue */
		binary_tree_t *node = queue[front++];

		/* Call function on current node */
		func(node->n);

		/* Add left child to queue if not NULL */
		if (node->left)
			queue[rear++] = node->left;

		/* Add right child to queue if not NULL */
		if (node->right)
			queue[rear++] = node->right;
	}
}
