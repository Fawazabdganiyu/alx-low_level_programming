#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list
 * @h: Head pointer.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes;

	if (head == NULL)
		return (98);

	nodes = 0;
	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head->next, head->n);
		nodes++;
		head = head->next;
	}
	return (nodes);
}
