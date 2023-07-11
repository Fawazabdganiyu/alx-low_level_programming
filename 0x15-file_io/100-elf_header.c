#include <elf.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident, char *elf_filename);
void print_magic_number(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_OSABI(unsigned char *e_ident);
void print_ABIversion(unsigned char *e_ident);
void print_type(uint16_t e_type);
void print_entry(Elf64_Addr e_entry);
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
		print_error_and_exit("Error: File %s is not an elf file\n", elf_filename);
	}
}

/**
 * print_magic_number - prints the magic numbers contained in an elf file.
 * @e_ident: The pointer to an array that contain the elf magic number.
 *
 * Description: prints the magic numbers in two digit hexadecimal form
 * separated by spaces and a newline after the last digit
 */
void print_magic_number(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of elf file header.
 * @e_ident: The pointer to an array that contain elf headerclass.
 *
 * Description: prints the class associated with an elf file,
 * followed by newline.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:			     ");

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("unknown: %x\n", e_ident[EI_CLASS]);
}

/**
 * print_data - prints elf file data type.
 * @e_ident: The pointer to an array that contain elf header data.
 *
 * Description: prints the data associated with an elf file
 * follwed by newline.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:				     ");

	if (e_ident[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("unknown: %x\n", e_ident[EI_DATA]);
}

/**
 * print_version - prints the version of elf header in elf file.
 * @e_ident: The pointer to an array that contain elf header version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:			     ");
	if (e_ident[EI_VERSION] == EV_NONE)
		printf("(invalid)\n");
	else if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", EV_CURRENT);
	else
		printf("unknown: %x\n", e_ident[EI_VERSION]);
}

/**
 * print_OSABI - prints the OS/ABI of the elf header.
 * @e_ident: The pointer to an array that contain OS\ABI
 * of elf header
 */
void print_OSABI(unsigned char *e_ident)
{
	printf("  OS/ABI:			     ");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE || e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone (embedded)\n");
	else
		printf("unknown: %x\n", e_ident[EI_OSABI]);
}

/**
 * print_ABIversion - prints ABIVERSION of elf header
 * @e_ident: A pointer to an array that contain ABIVersion of an elf header.
 */
void print_ABIversion(unsigned char *e_ident)
{
	printf("  ABI Version:			     %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints type of elf header.
 * @e_type: The elf type
 */
void print_type(uint16_t e_type)
{
	printf("  Type:				     ");

	if (e_type == ET_NONE)
		printf("NONE (Unknown file)\n");
	if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
}

/**
 * print_entry - prints entry point address of elf header
 * @e_entry: The elf header entry point address.
 */
void print_entry(Elf64_Addr e_entry)
{
	printf("  Entry point address:		     0x%lx\n", e_entry);
}

/**
 * _close - closes an elf file.
 * @elf_fd: The elf file file discriptor.
 *
 * Description: Closes elf file and exit with 98 if error.
 */
void _close(int elf_fd)
{
	int c;

	c = close(elf_fd);
	if (c < 0)
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
	if (elf_fd == -1)
		print_error_and_exit("Error: Can't read from file %s\n", av[1]);
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		_close(elf_fd);
		print_error_and_exit("Error: Can.t read from file %s\n", av[1]);
	}

	r = read(elf_fd, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		_close(elf_fd);
		print_error_and_exit("Error: Can't read from file %s\n", av[1]);
	}
	check_elf(header->e_ident, av[1]);
	printf("ELF Header:\n");
	print_magic_number(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_OSABI(header->e_ident);
	print_ABIversion(header->e_ident);
	print_type(header->e_type);
	print_entry(header->e_entry);

	free(header);
	_close(elf_fd);
	return (0);
}
