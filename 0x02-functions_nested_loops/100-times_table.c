#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: Times table to be printed.
 */
void print_times_table(int n)
{
	int i, j, t;

	if (n > 15 || n < 0)
	{
		;
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			_putchar('0');

			for (j = 1; j <= n ; j++)
			{
				_putchar(',');
				_putchar(' ');

				t = i * j;
				if (t <= 9)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (t >= 10 && t < 100)
				{
					_putchar(' ');
					_putchar((t / 10) + '0');
				}
				else if (t >= 100 && t < 1000)
				{
					_putchar((t / 100) + '0');
					t %= 100;
					_putchar((t / 10) + '0');
				}
				_putchar((t % 10) + '0');
			}
			_putchar('\n');
		}
	}
}
