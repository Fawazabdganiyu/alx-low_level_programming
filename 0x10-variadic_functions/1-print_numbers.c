#include "variadic_functions.h"

/**
 * print_numbers - Prints variable argument numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of intergers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator != NULL)
		{
			if (i != n - 1)
				printf("%s", separator);
		}
	}
	va_end(ap);

	printf("\n");
}
