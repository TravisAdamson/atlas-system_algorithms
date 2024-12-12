#include "nary_trees.h"

/**
 * nary_tree_insert - inserts a node in a N-ary tree
 *
 * @parent: pointer to the parent node
 * @str: string to be stored in node
 *
 * Return: pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_tree;
	char *new_str;

	new_tree = malloc(sizeof(nary_tree_t));
	if (!new_tree)
		return (NULL);
	new_str = strdup(str);
	if (!new_str)
	{
		free(new_tree);
		return (NULL);
	}

	new_tree->content = new_str;
	new_tree->parent = parent;
	new_tree->nb_children = 0;
	new_tree->children = NULL;
	new_tree->next = NULL;

	if (parent)
	{
		new_tree->next = parent->children;
		parent->children = new_tree;
		parent->nb_children++;
	}

	return (new_tree);
}
