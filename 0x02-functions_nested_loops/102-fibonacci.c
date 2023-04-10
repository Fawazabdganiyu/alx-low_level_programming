#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: Prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long a, b, sum;

	a = 0;
	b = 1;

	for (i = 0; i < 50; i++)
	{
		sum = a + b;
		printf("%lu", sum);

		a = b;
		b = sum;
		if (i < 49)
		{
			printf(", ");
		}
	}
	printf("\n");
	return (0);
}
