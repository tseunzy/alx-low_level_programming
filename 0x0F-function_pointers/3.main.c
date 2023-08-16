#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - funct to prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int num1, num2;
	int (*operation)(int, int);
	char *op = argv[2];
	int result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operation = get_op_func(op);

	if (operation == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' && num2 == 2) || (*op == '%' && num2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	result = operation(num1, num2);
	printf("%d\n", result);

	return (0);
}

