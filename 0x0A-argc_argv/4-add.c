#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * main - adds positive numbers.
 * @argc: The number of arguments passed to the program
 * @argv: An array of argument passed to the program.
 *
 * Return: If no number is passed to the program, print 0,
 *	followed by a new line
 *	If one of the number contains symbols that are not digits,
 *	print Error, followed by a new line, and return 1
 */
int main(int argc, char *argv[])
{
	int i, sum, num;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		int j;
		char *arg = argv[i];
		int len = strlen(arg);

		for (j = 0; j < len; j++)
		{
			if (!isdigit(arg[j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		num = atoi(arg);
		sum += num;
	}

	printf("%d\n", sum);
	return (0);
}
