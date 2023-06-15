#include "main.h"

/**
 * array_range - creates an array of integers.
 * @min: The minimum array element.
 * @max: The maximum integer.
 *
 * Return: The pointer to the newly created array.
 *	If min > max, return NULL
 *	If malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int i, size;
	int *arr;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}
	return (arr);
}
