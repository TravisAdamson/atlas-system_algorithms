#include "rb_trees.h"
#include "2-rb_tree_insert.c"

/**
 * tree_successor - program that finds the successor of a given node
 * in an in-order traversal of the tree
 *
 * @node: the node to find the successor for
 *
 * Return: a pointer to the successor node
 */

rb_tree_t *tree_successor(rb_tree_t *node)
{
	rb_tree_t *successor = node;

	if (successor->right != NULL)
	{
		successor = successor->right;
		while (successor->left != NULL)
			successor = successor->left;
	}
	else
	{
		while (successor->parent != NULL && successor == successor->parent->right)
			successor = successor->parent;
		successor = successor->parent;
	}
	return (successor);
}

/**
 * rb_tree_remove - Remove the given node from rb_tree
 *
 * @root: a pointer to the root of the red-black tree
 * @n: the value of the node to be removed
 *
 * Return: a pointer to the new root of the tree
 */

rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *target, *successor, *child, *parent;

	target = root;

	while (target != NULL && target->n != n)
	{
		if (n < target->n)
			target = target->left;
		else if (n > target->n)
			target = target->right;
	}
	if (target == NULL)
		return (root);

	if (target->left != NULL && target->right != NULL)
	{
		successor = tree_successor(target);
		target->n = successor->n;
		target = successor;
	}
	child = target->left != NULL ? target->left : target->right;
	parent = target->parent;

	if (child != NULL)
		child->parent = parent;
	if (parent == NULL)
		root = child;
	else if (target == parent->left)
		parent->left = child;
	else
		parent->right = child;
	if (target->color == BLACK)
		root = adjust_tree(root, target);

	free(target);

	return (root);
}
