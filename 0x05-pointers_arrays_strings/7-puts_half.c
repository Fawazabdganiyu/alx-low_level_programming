#include "main.h"

/**
 * puts_half - prints second half of a string
 * @str: The strings with characters.
 */
void puts_half(char *str)
{
	int len, i;

	len = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}

	if (len % 2 == 0)
	{
		for (i = (len / 2); i < len; i++)
		{
			_putchar(str[i]);
		}
	}
	else
	{
		for (i = ((len + 1) / 2); i < len; i++)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
