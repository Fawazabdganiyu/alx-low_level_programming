#include "lists.h"

size_t free_list(listint_t *h);
listint_t *check_loop(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * free_list - frees node
 * @h: The head pointer
 *
 * Return: Number of nodes freed
 */
size_t free_list(listint_t *h)
{
	listint_t *temp;
	size_t nodes = 0;

	while (h)
	{
		temp = h;
		h = temp->next;
		free(temp);
		++nodes;
	}

	return (nodes);
}

/**
 * check_loop - checks if the linked list has loop
 * @head: A pointer to the head node
 *
 * Return: A pointer to the meeting location in the search
 */
listint_t *check_loop(listint_t *head)
{
	listint_t *fast = head, *slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (fast);
	}

	return (NULL);
}

/**
 * free_listint_safe - frees a listint_t list.
 * @h: The pointer to head pointer.
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp, *fast, *slow;
	size_t nodes = 0;
	int freed = 0;

	if (h == NULL || *h == NULL)
		return ((size_t)NULL);

	/* Check if the list has loop */
	fast = check_loop(*h);
	/* If no loop, free the list */
	if (!fast)
	{
		nodes = free_list(*h);
		*h = NULL;
		return (nodes);
	}
	/* Set one of the (slow or fast) pointers back to the head */
	slow = *h;
	/* Get the location of the loop */
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	/* Free the list only once */
	nodes = 0;
	while (*h)
	{
		if (*h == slow)
			freed = 1;
		temp = *h;
		*h = temp->next;
		free(temp);
		++nodes;
		if ((*h == slow) && freed)
			break;
	}
	*h = NULL;

	return (nodes);
}
