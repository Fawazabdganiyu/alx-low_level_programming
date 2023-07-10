#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX
 *	standard output.
 * @filename: The name of file to read and print from.
 * @letters: The number of bytes it to be read and printed.
 *
 * Return: The actual number of letters it could read and print
 *	If the file can not be opened or read, return 0.
 *	If filename is NULL return 0
 *	If write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread = 0, written = 0;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	/* Allocate the buffer(buf) */
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	nread = read(fd, buf, letters);
	if (nread == -1)
		return (0);

	written = write(STDOUT_FILENO, buf, nread);
	if (written == -1)
		return (0);

	free(buf);

	close(fd);

	return (written);
}
