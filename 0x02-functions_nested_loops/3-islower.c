#include "main.h"

/**
 * _islower - check for lowercase character
 * @c: character to check
 *
 * Return: 1 for lowercase, 0 for otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
		return (0);
}
