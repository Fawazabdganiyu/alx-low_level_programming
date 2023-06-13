#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: the column of the array
 * @height: the row of the array
 *
 * Return: returns a pointer to a 2 dimensional array of integers.
 *	NULL on failure
 *	If width or height is 0 or negative, return NULL
 */
int **alloc_grid(int width, int height)
{
	int w, h, j;
	int **arr;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = malloc(sizeof(int *) * height);
	if (arr == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		arr[h] = malloc(sizeof(int) * width);
		if (arr[h] == NULL)
		{
			for (j = 0; j < h; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}

		for (w = 0; w < width; w++)
			arr[h][w] = 0;
	}

	return (arr);
}
