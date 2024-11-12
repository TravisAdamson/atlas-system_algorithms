#ifndef __RB_TREES_H__
#define __RB_TREES_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double black node
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

/* task 0 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);

/* task 1 */
int rb_tree_is_valid(const rb_tree_t *tree);
int bst_true(const rb_tree_t *tree, int *prev);
int check_colors(const rb_tree_t *tree);
size_t black_height(const rb_tree_t *tree);
size_t total_black_nodes(size_t left, size_t right);

/* task 2 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *add_rb_tree(rb_tree_t *tree, int value);
rb_tree_t *adjust_tree(rb_tree_t *root, rb_tree_t *node);
rb_tree_t *check_uncle(rb_tree_t *node);
rb_tree_t *parent_red_uncle_black(rb_tree_t *node);
rb_tree_t *rotate_left(rb_tree_t *tree);
rb_tree_t *rotate_right(rb_tree_t *tree);

/* task 3 */
rb_tree_t *array_to_rb_tree(int *array, size_t size);

/* task 4 */
rb_tree_t *tree_successor(rb_tree_t *node);
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);

#endif
