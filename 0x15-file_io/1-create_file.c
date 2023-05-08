#include "main.h"

/**
 * create_file - creates a file
 * @filename: Name of the file to be created.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure
 * if filename is NULL return -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len, written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	for (len = 0; text_content[len]; len++)
		;
	if (text_content != NULL)
	{
		written = write(fd, text_content, len);
		if (written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);

	return (1);
}
