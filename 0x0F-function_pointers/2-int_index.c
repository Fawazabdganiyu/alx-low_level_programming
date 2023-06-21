#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: The given array
 * @size: The number of elements in the array
 * @cmp: A function pointer to be used to compare values
 *
 * Return: The index of the first element for which the cmp function
 *	does not return 0
 *	-1 if no element matches
 *	-1 if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) == 1)
			return (i);
	}

	return (-1);
}
