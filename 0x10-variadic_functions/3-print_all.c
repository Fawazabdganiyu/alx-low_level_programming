#include "variadic_functions.h"

/**
 * _strcmp - compares strings".
 * @s1: The first string
 */
void _strcmp(char *s1)
{
	int i = 0;
	char *s2 = "NULL";

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			printf("%s", s1);
			return;
		}
		i++;
	}
	printf("(nil)");
}

/**
 * print_all - Prints anything.
 * @format: The list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	char c, *s;
	int i, j;
	float f;

	va_start(ap, format);
	while (format && format[j])
	{
		switch (format[j++])
		{
			case 'c':
				c = va_arg(ap, int);
				printf("%c", c);
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s == NULL)
				{
					printf("(nil)");
					break;
				}
				_strcmp(s);
				break;
			case 'i':
				i = va_arg(ap, int);
				printf("%d", i);
				break;
			case 'f':
				f = va_arg(ap, double);
				printf("%f", f);
				break;
			default:
				continue;
		}
		if (format[j])
			printf(", ");
	}
	va_end(ap);

	printf("\n");
}
