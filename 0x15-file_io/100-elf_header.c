#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_elf_header(Elf64_Ehdr *header);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 && e_ident[index] != 'E' && e_ident[index] != 'L' && e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_elf_header - Prints the ELF header information.
 * @header: A pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int index;

	printf("ELF Header:\n");
	printf(" Magic: ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", header->e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
	printf(" Class: ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}
	printf(" Data: ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}
	printf(" Version: %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
	printf(" OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf(" Type: ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
	}

	printf(" Entry point address: ");
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		unsigned long int e_entry = ((header->e_entry << 8) & 0xFF00FF00) |
			((header->e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			printf("%#x\n", (unsigned int)e_entry);
		else
			printf("%#lx\n", e_entry);
	}
	else
	{
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			printf("%#x\n", (unsigned int)header->e_entry);
		else
			printf("%#lx\n", header->e_entry);
	}
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int elf_fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(97);
	}

	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	if (read(elf_fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close_elf(elf_fd);
		exit(98);
	}

	check_elf(header.e_ident);
	print_elf_header(&header);

	close_elf(elf_fd);
	return (0);
}

