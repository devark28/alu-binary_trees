#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_stats - Evaluates the depth and matches perfection criteria
 * @tree: Pointer to structural context node
 * @d: Depth evaluation context
 * @level: Current depth traversal step
 *
 * Return: 1 if configuration is perfectly matching, 0 otherwise
 */
int tree_stats(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (tree_stats(tree->left, d, level + 1)
		&& tree_stats(tree->right, d, level + 1));
}

/**
 * find_depth - Evaluates the leftmost depth of the tree
 * @node: Pointer to the root node
 *
 * Return: Depth calculation integer
 */
int find_depth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if false or NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = find_depth(tree);
	return (tree_stats(tree, d, 0));
}
