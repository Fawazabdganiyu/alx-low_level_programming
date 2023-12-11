#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using
 *                 the Linear search algorithm
 * @array: A pointer to the first element of the array to be searched
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where the `value` is found
 *         -1 if `value` is not present or NULL
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array [%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}
