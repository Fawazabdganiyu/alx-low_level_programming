#include "search_algos.h"

/**
 * search - searches through the subarray using binary search algorithm
 * @array: A pointer to the first element of the array to be searched
 * @start: The first index of the subarray to be searched
 * @end: The last index of the subarray to be searched
 * @value: The value to be searched
 *
 * Return: The index where the value is located,
 *         -1 if the value is not present
 */
int search(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	if (start == end)
	{
		if (array[start] == value)
		{
			return ((int)start);
		}
		else
		{
			printf("Searching in array: %d\n", array[end]);
			return (-1);
		}
	}

	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = (start + end) / 2;
	if (array[mid] < value)
		return (search(array, mid + 1, end, value));
	else
		return (search(array, start, mid, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 *                   Advanced Binary search algorithm
 * @array: A pointer to the first element of the array to be searched
 * @size: The number of elements in the array
 * @value: The value to be searched
 *
 * Return: The index where the value is located,
 *         -1 if the value is not present or NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1;

	if (array == NULL)
		return (-1);

	return (search(array, start, end, value));
}
