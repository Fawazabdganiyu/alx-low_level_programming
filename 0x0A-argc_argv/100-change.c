#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money.
 * @argc: The number of arguments passed to the program
 * @argv: An array of argument passed to the program.
 *
 * Return: If the number of arguments passed to the program is not exactly 1,
 * print Error, followed by a new line, and return 1
 * If the number passed as the argument is negative, print 0,
 * followed by a new line, and return 0.
 */
int main(int argc, char *argv[])
{
	int cent;
	int n_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cent = atoi(argv[1]);
	if (cent < 0)
	{
		printf("0\n");
		return (0);
	}
	for (n_coins = 0; cent > 0; n_coins++)
	{
		if (cent >= 25)
		{
			cent -= 25;
		}
		else if (cent >= 10)
		{
			cent -= 10;
		}
		else if (cent >= 5)
		{
			cent -= 5;
		}
		else if (cent >= 2)
		{
			cent -= 2;
		}
		else
		{
			cent -= 1;
		}
	}
	printf("%d\n", n_coins);
	return (0);
}
