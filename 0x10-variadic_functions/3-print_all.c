#include "variadic_functions.h"

/**
 * _strcmp - compares strings".
 * @s1: first string
 *
 * Return: 0 if s1 == s2, (-) if s1 is less and (+) if s2 is greater
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
	const char *f_ptr;
	char c, *s;
	int i;
	float f;

	va_start(ap, format);
	f_ptr = format;
	while (f_ptr && *f_ptr)
	{
		switch (*f_ptr++)
		{
			case 'c':
				c = va_arg(ap, int);
				printf("%c", c);
				break;
			case 's':
				s = va_arg(ap, char *);
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

		if (*f_ptr)
			printf(", ");
	}
	va_end(ap);

	printf("\n");
}
