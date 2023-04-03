#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to be printed
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		_putchar((n / 10) + '0');
	}

	_putchar((n % 10) + '0');
}