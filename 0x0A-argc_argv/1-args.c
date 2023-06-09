#include <stdio.h>

/**
 * main - prints the number of arguments passed in.
 * @argc: The number of arguments passed into the program.
 * @argv: A pointer to an array of arguments passed into the program.
 *
 * Return:  Always 0.
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
