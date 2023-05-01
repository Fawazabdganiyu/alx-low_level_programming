#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list.
 * @head: The head pointer.
 * Return: The sum of all the data (n) of the list.
 * 0, if the list is empty.
 */
int sum_listint(listint_t *head)
{
	listint_t *current;
	int sum;

	if (head == NULL)
		return (0);

	sum = 0;
	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
