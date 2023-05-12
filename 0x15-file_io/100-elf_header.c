#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident, char *elf_filename);
void _close(int elf_fd);
void print_error_and_exit(char *message, char *elf_filename);
int main(int ac, char *av[]);

/**
 * check_elf - checks if the file given is elf file.
 * @e_ident: The array of bytes that must present in an elf file.
 * @elf_filename: The elf file filename.
 *
 * Description: Checks the first four bytes of the given file magic
 * number against e_ident bytes.
 */
void check_elf(unsigned char *e_ident, char *elf_filename)
{
	if ((e_ident[0] != ELFMAG0) &&
			(e_ident[1] != ELFMAG1) &&
			(e_ident[2] != ELFMAG2) &&
			(e_ident[3] != ELFMAG3))
	{
		print_error_and_exit("Error: The given file %s is not an elf file\n", elf_filename);
	}
}

/**
 * _close - closes an elf file.
 * @elf_fd: The elf file file discriptor.
 *
 * Description: Closes elf file and exit with 98 if error.
 */
void _close(int elf_fd)
{
	close(elf_fd);

	if (close(elf_fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close elf_fd %d\n", elf_fd);
		exit(98);
	}
}

/**
 * print_error_and_exit - prints error message and exit with code 98.
 * @message: Error message to be printed.
 * @elf_filename: The name of elf file provided.
 */
void print_error_and_exit(char *message, char *elf_filename)
{
	dprintf(STDERR_FILENO, message, elf_filename);
	exit(98);
}

/**
 * main - Entry point.
 * @ac: The number of argumwnts passed to the program.
 * @av: The array of arguments passed to the program.
 *
 * Description: displays the information contained in the ELF header
 * at the start of an ELF file
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	Elf64_Ehdr *header;
	int elf_fd, r;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", av[0]);
		exit(98);
	}

	elf_fd = open(av[1], O_RDONLY);
	if (elf_fd < 0)
		print_error_and_exit("Error: Can't read from file %s\n", av[1]);

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		_close(elf_fd);
		print_error_and_exit("Error: Can.t read from file %s\n", av[1]);
	}

	r = read(elf_fd, header, sizeof(Elf64_Ehdr));
	if (r < 0)
	{
		_close(elf_fd);
		print_error_and_exit("Error: Can't read from file %s\n", av[1]);
	}

	check_elf(header->e_ident, av[1]);

	free(header);
	_close(elf_fd);

	return (0);
}
