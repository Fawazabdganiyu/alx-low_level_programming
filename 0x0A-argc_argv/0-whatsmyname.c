#include <stdio.h>

/**
 * main - Prints its name, followed by a new line.
 * @argc: The number of command line arguments passed to the program.
 * @argv: A pointer to an array containing the program command line arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused))argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
