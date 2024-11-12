#include "graphs.h"

/**
 * graph_delete - completely deletes a given graph
 *
 * @graph: pointer to the given graph
 *
 * Return: None
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vec1 = NULL, *vec2 = NULL;
	edge_t *edge1 = NULL, *edge2 = NULL;

	if (!graph)
		return;

	vec1 = graph->vertices;
	while (vec1)
	{
		vec2 = vec1->next;

		if (vec1->content)
			free(vec1->content);

		edge1 = vec1->edges;
		while (edge1)
		{
			edge2 = edge1->next;
			free(edge1);
			edge1 = edge2;
		}

		free(vec1);
		vec1 = vec2;
	}

	free(graph);
}
