#include "rb_trees.h"


/**
 * array_to_rb_tree - builds a Red-Black Tree from the given array
 *
 * @array: array of integers
 * @size: amount of array members
 * Return: pointer to new rb tree created
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (rb_tree_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
				continue;

			if (j == i)
				return (NULL);
		}
	}

	return (tree);
}
