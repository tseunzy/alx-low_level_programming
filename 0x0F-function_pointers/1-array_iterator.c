#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - a funct prints each array element on \n
 * @array: array
 * @size: how many element to print
 * @action: pointer to print in regular
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array == NULL || action == NULL)
		return;

	while (i < size)
	{
		action(array[i]);
		i++;
	}
}

