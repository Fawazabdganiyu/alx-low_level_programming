#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of
 * a square matrix of integers.
 * @a: A pointer to the location of the first array element
 * @size: The size of the array
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int sum_diag_LR = 0;
	int sum_diag_RL = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				sum_diag_LR += a[i * size + j];
			}
			if (i + j == (size - 1))
			{
				sum_diag_RL += a[i * size + j];
			}
		}
	}
	printf("%d, %d\n", sum_diag_LR, sum_diag_RL);
}
