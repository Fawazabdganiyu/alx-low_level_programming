#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: The head pointer
 * @index: the index of the node, starting at 0
 *
 * Return: returns the nth node of a listint_t linked list.
 * If the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int currentIndex;

	current = head;
	currentIndex = 0;
	while (current != NULL)
	{
		if (currentIndex == index)
		{
			return (current);
		}
		current = current->next;
		currentIndex++;
	}
	return (NULL);
}
