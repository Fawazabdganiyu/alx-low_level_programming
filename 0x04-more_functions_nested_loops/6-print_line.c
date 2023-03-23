#include "main.h"

/**
 * print_line - draw a straight line using _
 * @n: number of times _ would be drawn
 *
 * Return: Straight line.
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
