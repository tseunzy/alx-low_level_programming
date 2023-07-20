#include "main.h"

/**
 * print_square -  a function that prints a square, followed by a new line.
 *
 * @size: Size of the square
 */
void print_square(int size)
{
	int m, k;

	k = 0;

	if (size < 1)
		_putchar('\n');

	while (k < size)
	{
		m = 0;
		while (m < size)
		{
			_putchar('#');
			m++;
		}
		_putchar('\n');
		k++;
	}
}
