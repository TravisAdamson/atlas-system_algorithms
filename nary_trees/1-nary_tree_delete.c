#include "nary_trees.h"

/**
 * nary_tree_delete - deletes an N-ary tree
 *
 * @parent: tree to delete
 *
 * Return: no return
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *temp_tree;

	if(!tree)
		return;
	while (tree->children)
	{
		temp_tree = tree->children;
		tree->children = tree->children->next;
		nary_tree_delete(temp_tree);
	}
	if (tree->content)
		free(tree->content);
	free(tree);
}
