#include"lists.h"

/**
 * find_listint_loop - find the loop in a linked list.
 * @head: The head poionter.
 *
 * Return: The address of node where the loop start, or
 * NULL, if there isno loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head, *slow = head;

	if (!head || !head->next)
		return (NULL);

	/* Check if the list has loop */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (!fast || !fast->next)
		return (NULL);

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
