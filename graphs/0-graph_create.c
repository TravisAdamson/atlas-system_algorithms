#include "graphs.h"

/**
 * graph_create - Creates a graph
 *
 * Return: pointer to created graph, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *graph = NULL;

	graph = malloc(sizeof(graph_t));
	if (!graph)
		return (NULL);

	graph->nb_vertices = 0;
	graph->vertices = NULL;

	return (graph);
}
