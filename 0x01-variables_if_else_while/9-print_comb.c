#include <stdio.h>

/**
 * main - Print all possible combinations of single-digit numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	num = 0;
	while (num < 10)
	{
		putchar((num % 10) + '0');
		if (num == 9)
		{
			num++;
			continue;
		}
		putchar(',');
		putchar(' ');
		num++;
	}
	putchar('\n');

	return (0);
}
