#include "nary_trees.h"

/**
 * nary_tree_traverse - traverses an N-ary tree
 *
 * @root: The root node of the tree
 * @action: the action to take on the tree
 * @_depth: current depth of the root
 *
 * Return: max depth of the tree at root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
						void (*action)(nary_tree_t const *node, size_t depth),
						size_t _depth)
{
	nary_tree_t *temp_tree;
	size_t count_children, max_depth, branch_depth;

	if (!root || !action)
		return (_depth ? _depth - 1 : 0);
	action(root, _depth);
	max_depth = 0;
	for (temp_tree = root->children, count_children = 0;
	     temp_tree && count_children < root->nb_children;
	     temp_tree = temp_tree->next, count_children++)
	{
		branch_depth = nary_tree_recurse(temp_tree, action, _depth + 1);
		if (branch_depth > max_depth)
			max_depth = branch_depth;
	}

	return (max_depth);
}
