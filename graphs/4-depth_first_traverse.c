#include "graphs.h"

#define MAX_VALUE(a, b) ((a) > (b) ? (a) : (b))


/**
 * depth_recursion - recursive function for depth_first_traverse
 *
 * @c_vertex: pointer to the current vertex
 * @checked: checked array of bytes indicating traversal history
 * @c_depth: depth of current vertex from the starting node
 * @action: pointer to a function to be called for each visited vertex, takes
 *   the parameters:
 *      v: const pointer to the visited vertex
 *      depth: depth of v, from the starting vertex
 * Return: largest vertex depth, or `c_depth` on failure
 */
size_t depth_recursion(vertex_t *c_vertex, unsigned char *checked, size_t c_depth,
		     void (*action)(const vertex_t *v, size_t depth))
{
	edge_t *temp_edge = NULL;
	size_t max_depth, subtree_depth;

	if (!c_vertex || !checked || !action)
		return (c_depth);

	checked[c_vertex->index] = 1;

	action(c_vertex, c_depth);

	max_depth = c_depth;
	temp_edge = c_vertex->edges;
	while (temp_edge)
	{
		if (!checked[temp_edge->dest->index])
		{
			subtree_depth = depth_recursion(temp_edge->dest, checked,
						      c_depth + 1, action);
			max_depth = MAX_VALUE(max_depth, subtree_depth);
		}

		temp_edge = temp_edge->next;
	}

	return (max_depth);

}

/**
 * depth_first_traverse - moves through a graph using depth-first
 *
 * @graph: pointer to given graph
 * @action: pointer to a function to be called for each visited vertex, takes
 *   the parameters:
 *      v: const pointer to the visited vertex
 *      depth: depth of v, from the starting vertex
 * Return: largest vertex depth, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	unsigned char *checked = NULL;
	size_t total_depth;

	if (!graph || !action)
		return (0);

	checked = malloc(sizeof(unsigned char) * graph->nb_vertices);
	if (!checked)
		return (0);
	memset(checked, 0, graph->nb_vertices);

	total_depth = depth_recursion(graph->vertices, checked, 0, action);
	free(checked);
	return (total_depth);
}
