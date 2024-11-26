#include "heap.h"

void remove_heap(btn *node, void (*free_data)(void *));

/**
 * heap_delete - Deletes a heap
 * @heap: heap to delete
 * @free_data: function to call on each node to free contents
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	remove_heap(heap->root, free_data);
	free(heap);
}

/**
 * remove_heap - Frees a tree recursively
 * @node: Node to free
 * @free_data: function to call on all nodes
 */
void remove_heap(btn *node, void (*free_data)(void *))
{
	if (!node)
		return;
	remove_heap(node->left, free_data);
	remove_heap(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}
