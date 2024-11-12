#include "graphs.h"

/**
 * graph_add_indiv_edge - adds an individual new edge between two vertices in
 * given graph
 *
 * @src: node originating the connection
 * @dest: node receiving the connection
 * Return: pointer to new edge on success, or NULL on failure
 */
edge_t *graph_add_indiv_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *add = NULL, *temp = NULL;

	if (!src || !dest)
		return (NULL);

	add = malloc(sizeof(edge_t));
	if (!add)
		return (NULL);
	add->dest = dest;
	add->next = NULL;

	temp = src->edges;
	while (temp && temp->next)
		temp = temp->next;

	if (temp)
		temp->next = add;
	else
		src->edges = add;
	src->nb_edges++;

	return (add);
}


/**
 * graph_add_edge - adds an edge between two vertices in given graph
 *
 * @graph: pointer to given graph
 * @src: string identifying the starting vertex in the connection
 * @dest: string identifying the ending vertex in the connection
 * @type: type of edge, valid values are:
 *          UNIDIRECTIONAL: only one edge is created from src to dest
 *          BIDIRECTIONAL: two edges created: from src to dest AND dest to src
 * Return: 1 on success, or 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *src,
		   const char *dest, edge_type_t type)
{
	vertex_t *temp_v = NULL, *src_v = NULL, *dest_v = NULL;

	if (!graph || !src || !dest ||
	    type < UNIDIRECTIONAL || type > BIDIRECTIONAL)
		return (0);

	for (temp_v = graph->vertices; temp_v; temp_v = temp_v->next)
	{
		if (strcmp(temp_v->content, src) == 0)
			src_v = temp_v;
		else if (strcmp(temp_v->content, dest) == 0)
			dest_v = temp_v;
	}

	if (!src_v || !dest_v)
		return (0);

	if (graph_add_indiv_edge(src_v, dest_v) == NULL)
		return (0);

	if (type == BIDIRECTIONAL)
	{
		if (graph_add_indiv_edge(dest_v, src_v) == NULL)
			return (0);
	}

	return (1);
}
