#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * ERR_EXIT - macro for error messages
 * @msg: The error message.
 * @fd: File descriptor.
 */
#define ERR_EXIT(msg, fd) { dprintf(STDERR_FILENO, "%s", msg); \
	if (fd != -1) close(fd); exit(98); }

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
 * check_elf - checks if given identifier is an ELF file.
 * @e_ident: The identifier to check.
 */
void check_elf(unsigned char *e_ident)
{
	if (strncmp((char *)e_ident, "\177ELF", 4) != 0)
		ERR_EXIT("Error: Not an ELF file\n", -1);
}

/* ... [Other function definitions remain unchanged] ... */

/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o;

	if (argc != 2)
		ERR_EXIT("Usage: elf_header <elf_filename>\n", -1);

	o = open(argv[1], O_RDONLY);
	if (o == -1)
		ERR_EXIT("Error: Can't read file\n", o);

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
		ERR_EXIT("Error: Memory allocation failed\n", o);

	if (read(o, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		free(header);
		ERR_EXIT("Error: Can't read ELF header\n", o);
	}

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

	free(header);
	close(o);
	return (0);
}

