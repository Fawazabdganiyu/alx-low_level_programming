#include "main.h"

/**
 * _abs - give the absolute value of an integer
 * @n: The integer to compute
 *
 * Return: r as the appropriate absolute value
 */
int _abs(int n)
{
	int r;

	if (n < 0)
	{
		r = n * -1;
		return (r);
	}
	else
	{
		r = n;
		return (r);
	}
}
