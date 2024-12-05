#include "pathfinding.h"

/**
 * backtracking_graph - Find a path with backtracking in graphs
 * @graph: graph to back track through
 * @start: starting vertex
 * @target: Target Vertex
 * Return: Queue containing the path, or NULL
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target)
{
	queue_t *new_que = NULL;
	int *current_visit;

	if (!graph || !start || !target)
		return (NULL);
	new_que = calloc(1, sizeof(queue_t));
	if (!new_que)
		return (NULL);
	current_visit = calloc(graph->nb_vertices, sizeof(int));
	if (!current_visit)
	{
		free(new_que);
		return (NULL);
	}
	if (!find_path(start, target, new_que, current_visit))
	{
		free(current_visit);
		free(new_que);
		current_visit = NULL, new_que = NULL;
	}
	free(current_visit);
	return (new_que);
}

/**
 * find_path - FInds the requested path
 * @vert: Vertex to check
 * @target: Target to look for
 * @que: que to hold the path
 * @visit: array to track if a vert has been visited
 * Return: que holding path, or NULL
 */
queue_t *find_path(vertex_t const *vert, vertex_t const *target,
				   queue_t *new_que, int *current_visit)
{
	edge_t *this_edge = vert->edges;

	if (!vert)
		return (NULL);
	if (GRAPH_CHECK)
		return (NULL);
	printf("Checking %s\n", vert->content);
	GRAPH_CHECK = 1;
	if (!strcmp(vert->content, target->content))
	{

		if (queue_push_front(new_que, strdup(vert->content)))
			return (new_que);
	}

	while (this_edge)
	{
		if (find_path(this_edge->dest, target, new_que, current_visit))
		{
			if (queue_push_front(new_que, strdup(vert->content)))
				return (new_que);
		}
		this_edge = this_edge->next;
	}
	return (NULL);
}
