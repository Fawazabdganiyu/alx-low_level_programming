#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @ac: Number of arguments passed
 * @av: Pointer to array of arguments passed
 *
 * Description: prints the opcodes of its own main function.
 *
 * Return: 0 on sucess
 */
int main(int ac, char **av)
{
	int num;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num = atoi(av[1]);
	if (num < 0)
	{
		printf("Error\n");
		exit(2);
	}

	return (0);
}
