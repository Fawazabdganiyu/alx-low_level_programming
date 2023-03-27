#include "main.h"

/**
 * swap_int - swap the value of two integers
 * @a: pointer to first variable
 * @b: pointer to second variable
 *
 * Return: nothing.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
