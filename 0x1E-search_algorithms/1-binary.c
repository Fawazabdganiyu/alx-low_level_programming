#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers using
 *                 Binary search algorithm
 * @array: A pointer to the first element of the array to be searched
 * @size: The number of elements in the array
 * @value: The value to be searched
 *
 * Return: The index where the value is located,
 *         -1 if the value is not present or NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r, m, i;

	if (array == NULL)
		return (-1);

	l = 0;
	r = size - 1;
	while (l <= r)
	{
		/* Display array elements */
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			printf("%d", array[i]);
			if (i != r)
				printf(", ");
			else
				printf("\n");
		}

		/* Search the array */
		m = (l + r) / 2;
		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			r = m - 1;
		else
			return ((int)m);
	}

	return (-1);
}
