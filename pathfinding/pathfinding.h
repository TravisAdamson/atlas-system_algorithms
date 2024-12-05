#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"

#define CHECKED current_visit[y * rows + x]
#define POINT map[next->y][next->x]
#define GRAPH_CHECK current_visit[vert->index]

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/* Prototypes */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

/* helper prototypes */
queue_t *recur_back(char **map, int rows, int cols,
					int x, int y, point_t const *target,
					queue_t *new_que, int *current_visit);
queue_t *find_path(vertex_t const *vert, vertex_t const *target, queue_t *new_que,
					int *current_visit);
#endif
