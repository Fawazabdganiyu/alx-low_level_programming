#include <stdio.h>

/**
 * main - Print all the numbers of base 16 in lowercase followed by a new line.
 *
 * Return: Always 0
 */
int main(void)
{
	int digit;
	char ch;

	digit = 0;
	while (digit < 10)
	{
		putchar((digit % 10) + '0');
		digit++;
	}

	ch = 'a';
	while (ch <= 'f')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');

	return (0);
}
