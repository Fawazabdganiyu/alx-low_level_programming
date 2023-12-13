#include <math.h>
#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted linked list of integers
 *             using the Jump search algorithm
 * @list: A pointer to the head of the list to be searched
 * @size: The number of nodes in the linked list
 * @value: The value to be searched
 *
 * Return: A pointer to the first node where `value` is found
 *         NULL if `value` is absent or the `list` is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *start = list, *end = list, *prev_e, *prev_s;
	size_t jump = sqrt(size), i;

	if (list == NULL)
		return (NULL);

	/* Jump through block */
	while (end->n < value && end != NULL)
	{
		start = end;
		for (i = 0; i < jump && end; i++)
		{
			prev_e = end;
			end = end->next;
		}
		if (!end)
		{
			end = prev_e;
			printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", start->index, end->index);

	/* Linear search through the identified block */
	while (start != end && start->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		prev_s = start;
		start = start->next;
	}

	start = !start ? prev_s : start;
	printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
	if (start && start->n == value)
		return (start);

	return (NULL);
}
