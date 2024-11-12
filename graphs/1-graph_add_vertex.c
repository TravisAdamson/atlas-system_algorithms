#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to an existing graph
 *
 * @graph: pointer to the graph to which vertex is added
 * @str: string to store in the new vertex
 * Return: pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *temp = NULL, *end = NULL, *added = NULL;
	size_t i, str_len;
	char *str_cpy = NULL;

	if (graph == NULL || str == NULL)
		return (NULL);

	for (i = 0, temp = graph->vertices; i < graph->nb_vertices; i++)
	{
		if (!temp || strcmp(temp->content, str) == 0)
			return (NULL);
		if (i == graph->nb_vertices - 1 && !temp->next)
			end = temp;
		temp = temp->next;
	}

	added = malloc(sizeof(vertex_t));
	if (!added)
		return (NULL);
	/* stores copy of string, not original */
	str_len = strlen(str);
	str_cpy = malloc(sizeof(char) * str_len + 1);
	if (!str_cpy)
	{
		free(added);
		return (NULL);
	}
	str_cpy = strcpy(str_cpy, str);
	added->index    = i;
	added->content  = str_cpy;
	added->nb_edges = 0;
	added->edges    = NULL;
	added->next     = NULL;

	if (end)
		end->next = added;
	else
		graph->vertices = added;
	graph->nb_vertices++;
	return (added);
}
