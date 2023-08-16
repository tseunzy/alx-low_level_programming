#include "function_pointers.h"
/**
 * int_index - a funct that search for an interger
 * @array: array
 * @size: size of elements in array
 * @cmp: pointer to funct to be compared
 * Return: index if comparison is true, else -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int *ptr;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	ptr = array;
	for (i = 0; i < size; i++)
	{
		if (cmp(*ptr))
			return (i);
		ptr++;
	}
	return (-1);
}

