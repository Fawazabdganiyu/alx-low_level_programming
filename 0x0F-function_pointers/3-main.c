#include "3-calc.h"

/**
 * main - entry point of program
 * @ac: the number of arguments passed to the program
 * @av: A pointer to an array of arguments passed to the program
 *
 * Description: performs simple operations.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int (*func)(int a, int b);
	int num1, num2;
	char *div = "/", *mod = "%";

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(av[1]);
	num2 = atoi(av[3]);

	if ((av[2][0] == *div || av[2][0] == *mod) && (num2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	func = get_op_func(av[2]);
	if (func != NULL)
	{
		printf("%d\n", func(num1, num2));
	}
	else
	{
		printf("Error\n");
		exit(99);
	}

	return (0);
}
