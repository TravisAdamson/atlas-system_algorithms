#include "rb_trees.h"

/**
 * rb_tree_insert - adds a new node to the given tree
 *
 * @tree: tree to add node to, or start if NULL
 * @value: value for the node
 * Return: pointer to added node, or NULL on failure or invalid value
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *add = NULL, *post_insert_root = NULL;

	if (!tree)
		add = add_rb_tree(NULL, value);
	else
		add = add_rb_tree(*tree, value);

	if (!add)
		return (NULL);

	post_insert_root = adjust_tree(*tree, add);
	if (!post_insert_root)
		return (NULL);

	*tree = post_insert_root;

	return (add);
}

/**
 * add_rb_tree - adds new node to correct location;
 *
 * @tree: Given tree to add node to, or start new if NULL
 * @value: value of added node
 * Return: pointer to added node, or NULL on failure or invalid value
 */
rb_tree_t *add_rb_tree(rb_tree_t *tree, int value)
{
	rb_tree_t *add = NULL;

	if (tree)
	{
		if (tree->n > value)
		{
			if (tree->left == NULL)
			{
				add = rb_tree_node(tree, value, RED);
				tree->left = add;
				return (add);
			}

			return (add_rb_tree(tree->left, value));
		}

		if (tree->n < value)
		{
			if (tree->right == NULL)
			{
				add = rb_tree_node(tree, value, RED);
				tree->right = add;
				return (add);
			}

			return (add_rb_tree(tree->right, value));
		}

		return (NULL);
	}

	return (rb_tree_node(NULL, value, RED));
}

/**
 * adjust_tree - Recolors tree to keep it valid
 *
 * @root: tree to adjust
 * @node: added node
 * Return: pointer to added root node, or NULL on failure
 */
rb_tree_t *adjust_tree(rb_tree_t *root, rb_tree_t *node)
{
	if (!node)
		return (root);

	if (node->parent == NULL)
	{
		node->color = BLACK;
		return (node);
	}
	else if (node->parent->color == BLACK)
	{
		return (root);
	}
	else if (check_uncle(node) != NULL &&
			 check_uncle(node)->color == RED)
	{
		node->parent->color = BLACK;
		check_uncle(node)->color = BLACK;
		node->parent->parent->color = RED;
		return (adjust_tree(root, node->parent->parent));
	}

	return (parent_red_uncle_black(node));
}

/**
 * check_uncle - Gets the uncle of given node
 *
 * @node: starting node
 * Return: pointer to uncle node, or NULL if parent or grandparent missing
 */
rb_tree_t *check_uncle(rb_tree_t *node)
{
	rb_tree_t *parent = NULL;

	if (node)
		parent = node->parent;

	if (!parent || !parent->parent)
		return (NULL);

	if (parent == parent->parent->left)
		return (parent->parent->right);

	return (parent->parent->left);
}

/**
 * parent_red_uncle_black - Adjusts tree as needed in this situation
 *
 * @node: added node
 * Return: pointer to new root node, or NULL on failure
 */
rb_tree_t *parent_red_uncle_black(rb_tree_t *node)
{
	rb_tree_t *parent = NULL, *g_parent = NULL, *post_root = NULL;

	if (node)
		parent = node->parent;
	if (parent)
		g_parent = parent->parent;
	if (!parent || !g_parent)
		return (NULL);
	if (node == parent->right && parent == g_parent->left)
	{
		post_root = rotate_left(parent);
		node = node->left;
	}
	else if (node == parent->left && parent == g_parent->right)
	{
		post_root = rotate_right(parent);
		node = node->right;
	}
	if (node)
		parent = node->parent;
	else
		parent = NULL;
	if (parent)
		g_parent = parent->parent;
	else
		g_parent = NULL;
	if (node == parent->left)
		post_root = rotate_right(g_parent);
	else
		post_root = rotate_left(g_parent);
	while (post_root && post_root->parent)
		post_root = post_root->parent;
	parent->color = BLACK;
	g_parent->color = RED;
	return (post_root);
}

/**
 * rotate_left - left child becomes root
 *
 * @tree: tree to rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */
rb_tree_t *rotate_left(rb_tree_t *tree)
{
	rb_tree_t *rotated = NULL;

	if (!tree)
		return (NULL);

	rotated = tree->right;
	tree->right = rotated->left;

	if (rotated->left)
		rotated->left->parent = tree;

	rotated->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = rotated;
		else
			tree->parent->right = rotated;
	}

	rotated->left = tree;
	tree->parent = rotated;

	return (rotated);
}

/**
 * rotate_right - Right child becomes new root, tree rotated
 *
 * @tree: tree to right rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */
rb_tree_t *rotate_right(rb_tree_t *tree)
{
	rb_tree_t *rotated = NULL;

		if (!tree)
			return (NULL);

	rotated = tree->left;

	tree->left = rotated->right;
	if (rotated->right)
		rotated->right->parent = tree;

	rotated->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = rotated;
		else
			tree->parent->left = rotated;
	}

	rotated->right = tree;
	tree->parent = rotated;

	return (rotated);
}
