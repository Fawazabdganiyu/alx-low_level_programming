#include "main.h"

/**
 * _isalpha - check for lowercase or uppercase character
 * @c: character to check
 *
 * Return: 1 for alphabet, 0 for otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
