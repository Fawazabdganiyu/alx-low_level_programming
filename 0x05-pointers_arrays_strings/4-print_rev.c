#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @s: string to be printed in reverse
 */
void print_rev(char *s)
{
	int lens, i;

	lens = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		lens++;
	}

	for (i = lens - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
