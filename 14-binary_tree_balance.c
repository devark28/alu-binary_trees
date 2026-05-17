#include <stdlib.h>
#include "binary_trees.h"

/**
 * height_helper - Measures the height of a binary tree for balance check
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t height_helper(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + height_helper(tree->left) : 1;
	right_h = tree->right ? 1 + height_helper(tree->right) : 1;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? (int) height_helper(tree->left) : 0;
	right_height = tree->right ? (int) height_helper(tree->right) : 0;

	return (left_height - right_height);
}
