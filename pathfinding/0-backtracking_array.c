#include "pathfinding.h"

/**
 * backtracking_array - Function for finiding a path from start to target
 * @map: Read-only 2d aray
 * @rows: Num of rows
 * @cols: Num of cols
 * @start: pointer to start of path
 * @target: pointer to end of path
 * Return: pointer to que holding the path
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target)
{
	queue_t *new_que = NULL;
	int *current_visit, x = 0, y = 0;

	if (!map || !rows || !cols || !start || !target)
		return (NULL);

	new_que = queue_create();
	if (!new_que)
		return (NULL);

	current_visit = calloc((rows * cols), sizeof(int));
	if (!current_visit)
	{
		free(new_que);
		return (NULL);
	}
	x = start->x;
	y = start->y;
	if (!recur_back(map, rows, cols, x, y, target, new_que, current_visit))
	{
		free(new_que), free(current_visit);
		new_que = NULL, current_visit = NULL;
		return (NULL);
	}
	free(current_visit);
	current_visit = NULL;
	return (new_que);
}

/**
 * recur_back - Recursive function for pathfinding
 * @map: Read-only 2d aray
 * @rows: Num of rows
 * @cols: Num of collumns
 * @x: x point to check
 * @y: y point to check
 * @target: pointer to end of the path
 * @new_que: Que to hold the path
 * @current_visit: array to track if point has been visited
 * Return: pointer to que holding the path
 */
queue_t *recur_back(char **map, int rows, int cols,
					int x, int y, point_t const *target,
					queue_t *new_que, int *current_visit)
{
	point_t *point = NULL;

	if (x < 0 || x > cols - 1 || y < 0 || y > rows - 1 || map[y][x] == '1'
		|| CHECKED)
		return (NULL);
	CHECKED = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == target->x && y == target->y) ||
		recur_back(map, rows, cols, x + 1, y, target, new_que, current_visit) ||
		recur_back(map, rows, cols, x, y + 1, target, new_que, current_visit) ||
		recur_back(map, rows, cols, x - 1, y, target, new_que, current_visit) ||
		recur_back(map, rows, cols, x, y - 1, target, new_que, current_visit))
	{
		point = malloc(sizeof(point_t));
		point->x = x, point->y = y;
		queue_push_front(new_que, (void *)point);
		return (new_que);
	}
	return (NULL);
}
