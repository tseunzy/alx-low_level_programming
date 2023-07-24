#include "main.h"

/**
 * swap_int - a function that swaps the values of two integers.
 * @a: integer
 * @b: integer
 * return: 0
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
