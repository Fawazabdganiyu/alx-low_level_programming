#include <stdio.h>

/**
 * main - print 1 - 100, except multiples of 3, 5 and both
 *
 * Return: Always 0.
 */
int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 3 == 0)
		{
			printf("Fizz");
		}
		else if (num % 5 == 0)
		{
			printf("Buzz");
		}
		else if (num % 15 == 0)
		{
			printf("FizzBuzz");
		}
		else
		{
			printf("%d", num);
		}
		if (num == 100)
		{
			continue;
		}
		printf(" ");
	}
	printf("\n");

	return (0);
}
