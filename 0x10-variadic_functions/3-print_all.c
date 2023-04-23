#include <stdarg.h>
#include <stdio.h>

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
	while (*f_ptr)
	{
		switch (*f_ptr++)
		{
			case 'c':
				c = (char)va_arg(ap, int);
				printf("%c", c);
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s == NULL)
					printf("(nil)");
				printf("%s", s);
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
