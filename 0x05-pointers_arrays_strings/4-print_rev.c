#include "main.h"

/**
 * _print_rev - prints a string in reverse
 * @s: string to be printed in reverse
 */
void print_rev(char *s)
{
	int i;

	for (i = _strlen(s); s[i] != '\2'; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
