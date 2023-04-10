#include "main.h"

/**
 * times_table - Print the 9 times table starting with 0
 *
 * Return: 0
 */
void times_table(void)
{
	int i, j, t;

	for (i = 0; i < 10; i++)
	{
		_putchar('0');
		_putchar(',');
		_putchar(' ');

		for (j = 1; j < 10; j++)
		{
			t = i * j;
			if (t <= 9)
			{
				_putchar(' ');
			}
			else
			{
				_putchar((t / 10) + '0');
			}
			_putchar((t % 10) + '0');
			if (j != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
