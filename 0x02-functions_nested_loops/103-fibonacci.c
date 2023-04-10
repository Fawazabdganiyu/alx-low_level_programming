#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: prints the sum of the even-valued terms,
 * not exceeding 4 000 000, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long a, b, sum, total;

	a = 0;
	b = 1;
	total = 0;

	for (i = 0; i >= 0; i++)
	{
		sum = a + b;
		if (sum >= 4000000)
		{
			break;
		}
		if (sum % 2 == 0)
		{
			total += sum;
		}

		a = b;
		b = sum;
	}
	printf("%lu\n", total);
	return (0);
}
