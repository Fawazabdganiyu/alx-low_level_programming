#include <stdio.h>

/**
 * main - Entry point
 * count: counter
 *
 * Description: This program prints the alphabet in lowercase except q and e.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char count;

	count = 97;
	while (count <= 122)
	{
		if (count == 101 || count == 113)
		{
			count++;
			continue;
		}
		putchar(count);
		count++;
	}
	putchar('\n');

	return (0);
}
