#include "main.h"
#include <stdlib.h>
/**
 * create_array -  a function that create array of size size and assign char c
 * @size: size of array
 * @c: char to assign
 * Return: pointer to array, NULL if fail
 *
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	char *array = (char *) malloc(sizeof(char) * size);

	if (size == 0 || array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;
	return (array);
}
