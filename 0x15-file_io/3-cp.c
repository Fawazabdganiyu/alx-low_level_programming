#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output.
 * @filename: The name of file to read and print from.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and printed
 * if the file can not be opened or read, return 0.
 * If filename is NULL return 0
 * If write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, nread, printed;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = 0;
	nread = 0;
	printed = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(letters * sizeof(char));
	if (buffer == NULL)
		return (0);

	nread = read(fd, buffer, letters);
	if (nread == -1)
		return (0);

	printed = write(STDOUT_FILENO, buffer, nread);
	if (printed == -1)
		return (0);

	free(buffer);

	close(fd);

	return (printed);
}

