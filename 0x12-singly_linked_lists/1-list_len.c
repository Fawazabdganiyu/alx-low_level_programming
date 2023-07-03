#include "lists.h"

/**
 * list_len - return the number of elements in a linkedd list_t list
 * @h: A pointer to the head node
 *
 * Return: The number of elements in the list.
 */
size_t list_len(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
