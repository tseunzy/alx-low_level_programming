#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char e_ident[]);
void print_magic(unsigned char e_ident[]);
void print_class(unsigned char e_ident[]);
void print_data(unsigned char e_ident[]);
void print_version(unsigned char e_ident[]);
void print_osabi(unsigned char e_ident[]);
void print_abi(unsigned char e_ident[]);
void print_type(uint16_t e_type, unsigned char e_ident[]);
void print_entry(uint64_t e_entry, unsigned char e_ident[]);


/**
 * error_exit - Exits with an error message.
 * @msg: The error message.
 * @fd: The file descriptor to close.
 * @header: The header to free.
 */
void error_exit(const char *msg, int fd, Elf64_Ehdr *header)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	if (header)
		free(header);
	if (fd != -1)
		close(fd);
	exit(98);
}

/**
 * read_elf_header - Reads the ELF header from a file.
 * @file_name: The file name.
 * @fd: The file descriptor pointer.
 * Return: The header.
 */
Elf64_Ehdr *read_elf_header(const char *file_name, int *fd)
{
	Elf64_Ehdr *header;

	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		error_exit("Can't read file", -1, NULL);

	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
		error_exit("Memory allocation failed", *fd, NULL);

	if (read(*fd, header, sizeof(Elf64_Ehdr)) == -1)
		error_exit("No such file", *fd, header);

	return (header);
}

/**
 * display_elf_header - Displays the ELF header details.
 * @header: The header.
 */
void display_elf_header(Elf64_Ehdr *header)
{
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: Always 0 (success).
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int fd;
	Elf64_Ehdr *header = read_elf_header(argv[1], &fd);

	display_elf_header(header);

	free(header);
	close(fd);
	return (0);
}

