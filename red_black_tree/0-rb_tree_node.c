#include "rb_trees.h"

/**
 * rb_tree_node - makes new node for rb tree
 *
 * @parent: pointer to node to be parent
 * @value: value for new node
 * @color: red or black indicator
 * Return: pointer to created node
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new;

	new = malloc(sizeof(rb_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->color = color;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
