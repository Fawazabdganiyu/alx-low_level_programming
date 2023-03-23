#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - Print all natural numbers from n to 98.
 * @n: Starting point
 *
 * Return: Always 0.
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		int i;

		for (i = n; i < 98; i++)
		{
			printf("%d, ", i);
		}
		printf("%d\n", i);
	}
	else
	{
		int j;

		for (j = n; j > 98; j--)
		{
			printf("%d, ", j);
		}
		printf("%d\n", j);
	}
}
