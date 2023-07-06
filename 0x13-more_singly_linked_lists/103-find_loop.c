#include"lists.h"

/**
 * find_loop - checks if the linked list has loop
 * @head: A pointer to the head node
 *
 * Return: A pointer to the meeting location in the search
 */
listint_t *find_loop(listint_t *head)
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
 * find_listint_loop - find the loop in a linked list.
 * @head: The head poionter.
 *
 * Return: The address of node where the loop start, or
 * NULL, if there isno loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	/* Check if the list has loop */
	fast = find_loop(head);
	if (fast)
	{
		/* Set one of the (slow or fast) pointers back to the head */
		slow = head;
		/* Get the location of the loop */
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return (slow);
	}

	return (NULL);
}
