#include "main.h"

/**
 * puts2 - prints every other character of a string, starting with the first character
 *@str: input string
 *
 */
void puts2(char *str)
{
	int i, len;

	len = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}

	for (i = 0; i <= len - 1; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
