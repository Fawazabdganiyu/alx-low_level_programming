#include "variadic_functions.h"

/**
 * sum_them_all - Calculates the sum of all its parameters
 *	after the first parameter given..
 * @n: The first parameter given that specify the numbers
 *	variable arguments to be received.
 *
 * Return: The sum of all the parameters on success.
 *	0 if n == 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	unsigned int sum;

	if (n == 0)
		return (0);

	sum = 0;
	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);

	return (sum);

}

