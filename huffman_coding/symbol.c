#include "huffman.h"

/**
 * symbol_create - Creates a struct - symbol
 * @data: Data to add to symbol
 * @freq: Frequency of symbol
 * Return: Pointer to new symbol, or NULL on Fail
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_sym = NULL;

	if (!data)
		return (NULL);

	new_sym = malloc(sizeof(symbol_t));
	if (!new_sym)
		return (NULL);
	new_sym->data = data;
	new_sym->freq = freq;
	return (new_sym);
}
