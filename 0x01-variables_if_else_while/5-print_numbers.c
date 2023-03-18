#include <stdio.h>

/**
 * main - Print all single digits in base 10.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		printf("%u", i);
		i++;
	}
	putchar('\n');
	return (0);
}
