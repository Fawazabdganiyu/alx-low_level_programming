#include <stdio.h>
#include <stdlib.h>
#include "main.h"

buffer_t *init_buff(void);
void clear_buffer(buffer_t *buff);
void cp(int fd_r, int fd_w, const char *file_from, const char *file_to);
void process(const char *file_from, const char *file_to);
int main(int ac, char **av);

/**
 * init_buff - initialises temporary buffer
 *
 * Return: A pointer to the initialised buffer
 */
buffer_t *init_buff(void)
{
	buffer_t *buff;

	buff = malloc(sizeof(buffer_t));
	if (buff == NULL)
		return (0);

	buff->buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buff->buf == NULL)
	{
		free(buff);
		return (NULL);
	}

	buff->start = buff->buf;

	return (buff);
}

/**
 * clear_buffer - sets buffer back to the first memory address
 * @buff: The temporary buffer used
 */
void clear_buffer(buffer_t *buff)
{
	buff->buf = buff->start;
}

/**
 * cp - copies the content of a file to another file.
 * @fd_r: file descriptor for the opened source file
 * @fd_w: file descriptor for the opened destination file
 * @file_from: Source file to copy from
 * @file_to: Destination file to copy to
 */
void cp(int fd_r, int fd_w, const char *file_from, const char *file_to)
{
	ssize_t nread, written;
	buffer_t *buff;

	buff = init_buff();
	do {
		nread = read(fd_r, buff->buf, BUFFER_SIZE);
		if (nread == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}
		written = write(fd_w, buff->buf, nread);
		if (written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		clear_buffer(buff);
	} while (nread == BUFFER_SIZE);

	free(buff->buf);
	free(buff);
}

/**
 * process - reads the content of a file and write it to another.
 * @file_from: The file to read from.
 * @file_to: The name of the file to be written to.
 */
void process(const char *file_from, const char *file_to)
{
	int fd_w;
	ssize_t fd_r, c;

	fd_r = open(file_from, O_RDONLY);
	fd_w = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
			S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	if (fd_r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	cp(fd_r, fd_w, file_from, file_to);

	c = close(fd_w);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		exit(100);
	}

	c = close(fd_r);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %ld\n", fd_r);
		exit(100);
	}

	exit(EXIT_SUCCESS);
}

/**
 * main - Entry point
 * @ac: The number of arguments passed to the program.
 * @av: The array of arguments passed to the program.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (av[1] == NULL || av[2] == NULL)
		return (1);

	process(av[1], av[2]);

	return (0);
}
