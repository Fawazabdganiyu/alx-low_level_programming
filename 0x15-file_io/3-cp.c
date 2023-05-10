#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

ssize_t _read_and_write(const char *file_from, const char *file_to);
ssize_t cp(const char *file_from, const char *file_to);
int main(int ac, char *av[]);

/**
 * _read_and_write - reads the content of a file and write it to another.
 * @file_from: The file to read from.
 * @file_to: The name of the file to be written to.
 *
 * Return: 1 on succes and 0, on failure
 */
ssize_t _read_and_write(const char *file_from, const char *file_to)
{
	int fd_w, w;
	ssize_t fd_r, r, c;
	char buffer[BUFFER_SIZE];

	if (file_from == NULL)
		return (0);

	fd_r = open(file_from, O_RDONLY);
	fd_w = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	while ((r = read(fd_r, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_w, buffer, r);
	}
	if (fd_r < 0 || r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	if (fd_w < 0 || w < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		c = close(fd_w);
		if (c < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can'tclose fd %d\n", fd_w);
			exit(100);
		}
		exit(99);
	}
	c = close(fd_w);
	if (c < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		exit(100);
	}

	c = close(fd_r);
	if (c < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %ld\n", fd_r);
		exit(100);
	}

	return (1);
}

/**
 * cp - copies the content of a file to another file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 *
 * Return: 1 on success -1 on failure.
 */
ssize_t cp(const char *file_from, const char *file_to)
{
	ssize_t rd;

	rd = _read_and_write(file_from, file_to);
	if (rd == 0)
		return (0);

	return (1);
}

/**
 * main - Entry point
 * @ac: The number of arguments passed to the program.
 * @av: The array of arguments passed to the program'
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

		cp(av[1], av[2]);

	return (0);
}
