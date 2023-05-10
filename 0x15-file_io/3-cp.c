#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int _write(const char *file_to, char *text_content, int num);
ssize_t _read(const char *file_from, const char *file_to);
ssize_t cp(const char *file_from, const char *file_to);
int main(int ac, char *av[]);

/**
 * _write - writes to file, create it if it does not exist.
 * @file_to: The name of the file to be written to.
 * @text_content: The character strings to write
 * @num: The number of characters to be written.
 *
 * Return: 1 on success, 0 on failure
 */
int _write(const char *file_to, char *text_content, int num)
{
	int fd, w, c;

	if (file_to == NULL)
		return (0);

	fd = open(file_to, O_CREAT | O_RDWR | O_TRUNC, 0706);
	w = write(fd, text_content, num);
	if (fd == -1 || w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		c = close(fd);
		if (c == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can'tclose fd %d\n", fd);
			exit(100);
		}
		exit(99);
	}
	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	return (1);
}

/**
 * _read - reads the content of a file.
 * @file_from: The file to read from.
 * @file_to: The name of the file to be written to.
 *
 * Return: 1 on succes and 0, on failure
 */
ssize_t _read(const char *file_from, const char *file_to)
{
	ssize_t fd, r, c;
	char buffer[1024];

	if (file_from == NULL)
		return (0);

	fd = open(file_from, O_RDONLY);
	r = read(fd, buffer, 1024);

	if (fd == -1 || r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %ld\n", fd);
		exit(100);
	}

	_write(file_to, buffer, r);

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

	rd = _read(file_from, file_to);
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
