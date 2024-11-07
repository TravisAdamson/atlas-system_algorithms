#include "rb_trees.h"

/**
 * rb_tree_is_valid - Checks that tree meets all rb reqs
 *
 * @tree: pointer to root node or subtree
 * Return: 1 if valid, 0 if not
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	if (!bst_true(tree, &prev))
		return (0);

	return (check_colors(tree));
}

/**
 * bst_true - Checks if the tree is a valid bst
 * @tree: A node in the tree to check
 * @prev: Starting int
 *
 * return: 1 if valid, 0 if not or if tree is NULL
*/
int bst_true(const rb_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!bst_true(tree->left, prev))
			return (0);
		if (tree->n <= *prev)
			return (0);
		*prev = tree->n;
		return (bst_true(tree->right, prev));
	}
	return (1);
}

/**
 * check_colors - Checks that the node colors are valid
 * @tree: A node in the tree to check
 *
 * return: 1 if colors are valid, 0 if not or if NULL tree
*/
int check_colors(const rb_tree_t *tree)
{
	if (tree)
	{
		if (!(tree->parent))
		{
			if (tree->color != BLACK)
				return (0);
		}
		else if (tree->color == RED)
		{
			if ((tree->parent == RED) ||
			(tree->left && tree->left->color == RED) ||
			(tree->right && tree->right->color == RED))
				return (0);
		}

		if (black_height(tree->left) !=
			black_height(tree->right))
				return (0);

		return (check_colors(tree->left) &&
				check_colors(tree->right));
	}

	return (1);
}

/**
 * black_height - Checks that black nodes top to bottom are equal
 *
 * @tree: A node in the tree to check
 *
 * Return: Number of black from root to leaf, or 1 if tree is NULL
*/
size_t black_height(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color == BLACK)
		return (1 + total_black_nodes(black_height(tree->left),
									black_height(tree->right)));
	else
		return (total_black_nodes(black_height(tree->left),
								black_height(tree->right)));
}

/**
 * total_black_nodes - Finds the max nodes recursively
 *
 * @left: left side
 * @right: right side
 *
 * return: The highest value of the two
*/
size_t total_black_nodes(size_t left, size_t right)
{
	if (left > right)
		return (left);
	else
		return (right);
}
