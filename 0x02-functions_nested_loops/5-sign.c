#include "main.h"

/**
 * print_sign - Print the sign of a number
 * @n: number to check
 *
 * Return: 1 for greater than zero, 0 for zero and -1 for less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
