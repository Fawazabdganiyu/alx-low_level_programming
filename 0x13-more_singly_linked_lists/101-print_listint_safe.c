#include "lists.h"

size_t no_loop_print(const listint_t *head);
const listint_t *detect_loop(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * no_loop_print - Prints linked list with no loop
 * @head: A pointer to the head node
 *
 * Return: The number of nodes in the list
 */
size_t no_loop_print(const listint_t *head)
{
	size_t nodes = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;
		head = head->next;
	}

	return (nodes);
}

/**
 * detect_loop - checks if the linked list has loop
 * @head: A pointer to the head node
 *
 * Return: A pointer to the meeting location in the search
 */
const listint_t *detect_loop(const listint_t *head)
{
	const listint_t *fast = head, *slow = head;

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
 * print_listint_safe - prints a listint_t list
 * @head: Head pointer.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes;
	int printed = 0;
	const listint_t *fast = head, *slow = head, *temp = head;

	if (head == NULL)
		return(0);

	/* Check if the list has loop */
	fast = detect_loop(head);
	/* If no loop, print the list */
	if (!fast)
	{
		nodes = no_loop_print(head);
		return (nodes);
	}

	/* Set one of the (slow or fast) pointers back to the head */
	slow = head;
	/* Get the location of the loop */
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	/* Print the list only once */
	nodes = 0;
	temp = head;
	while (temp)
	{
		if (temp == slow)
			printed = 1;
		printf("[%p] %d\n", (void *)temp, temp->n);
		nodes++;
		temp = temp->next;
		if ((temp == slow) && printed)
			break;
	}
	printf("-> [%p] %d\n", (void *)slow, slow->n);
	return (nodes);
}
