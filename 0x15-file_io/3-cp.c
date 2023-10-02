#include "main.h"

/*
 * *create_buffer - Func allocates memory for a buffer
 * @file: checks for successful allocation.
 */
char create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(1024);

	/* Checking if buffer allocation is successful */
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/*
 * close_file - Func closes a file descriptor and checks for succes clos
 * @fd: file descriptor
 */
void close_file(int fd)
{
	/* Closing the file descriptor and storing the result */
	int c = close(fd);

	/* Checking if file closing is successful */
	if (c == -1)
	{
		/* Printing error message and exiting if file closing fails */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file
 * @argc: num of argu supplied to the program
 * @argv: an array of pointer to the arguments
 * Description:
 *   If the argument count is incorrect - exit code 97
 *   If file_from does not exist or cannot be read - exit code 98
 *   If file_to cannot be created or written to - exit code 99
 *   If file_to or file_from cannot be closed - exit code 100
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		perror("Error opening source file");
		free(buffer);
		exit(98);
	}
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (r == -1)
		{
			perror("Error reading from source file");
			free(buffer);
			close_file(from);
			exit(98);
		}
		w = write(to, buffer, r);
		if (w == -1)
		{
			perror("Error writing to destination file");
			free(buffer);
			close_file(from);
			exit(99);
		}
		r = read(from, buffer, 1024);
	} while (r > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
