#include <math.h>
#include "search_algos.h"

/**
 * _min - finds mininum of two integers
 * @num1: The first integer
 * @num2: The second integer
 *
 * Return: The mininum integer
 */
int _min(int num1, int num2)
{
	return ((num1 < num2) ? num1 : num2);
}

/**
 * jump_search - searches for a value in a sorted array of integers
 *               using the Jump search algorithm
 * @array: A pointer to the first element of the array to be searched
 * @size: The number of elements in the array
 * @value: The value to be searched
 *
 * Return: The first index where `value` is found
 *         -1 if the `array` is NULL or if `value` is not present
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, start, end, i, low, high;

	if (array == NULL)
		return (-1);

	start = 0;
	end = jump = sqrt(size);
	/* Jump through block */
	do {
		low = start;
		high = end;
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);

		start = end;
		end += jump;

	} while ((array[_min(end, size) - 1] < value) && start < size);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	if (start >= size)
		high = size - 1;

	/* Linear search through the identified block */
	for (i = low; i <= high; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}
