#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: A pointer to the head of the list to be searched
 * @value: The value to be searched
 *
 * Return: A pointer to the first node where `value` is found
 *         NULL if `value` is absent or the `list` is NULL
 *
 * Description: This is a way to optimize the time complexity of a search
 *              in a singly linked list by adding an "express lane" to
 *              browse the list. Hence a "skip list".
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start = list, *end = list;

	if (list == NULL)
		return (NULL);

	/* Jump through block */
	while (end->n < value && end->express != NULL)
	{
		start = end;
		end = end->express;
		printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", start->index,
	       start->index);

	/* Linear search through the identified block */
	while (start != end && start->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		start = start->next;
	}
	printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);

	if (start && start->n == value)
		return (start);

	return (NULL);
}
