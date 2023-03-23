#include "main.h"

/**
 * _isupper - Check for uppercase character
 * @c: Character to check
 *
 * Return: 1 if c is uppercase, 0 if otherwise.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
