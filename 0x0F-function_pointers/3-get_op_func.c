#include "3-calc.h"
#include <stdlib.h>
#include <string.h>
/**
 * get_op_func - a funct to perform the operation asked by the user
 * @s: The operator passed as argument.
 * Return: Pointer to the funct corresponding to operato given as a para
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};

	int i;

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
	}
	return (NULL);
}

