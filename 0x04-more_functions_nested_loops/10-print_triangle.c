#include "main.h"

/**
 * print_triangle -  a function that prints a triangle, followed by a new line
 * @size: Size of the triangle
 * Return: Always 0
 */
void print_triangle(int size)
{
	int m, k;

	if (size > 0)
	{
		for (m = 1; m <= size; m++)
		{
			for (k = size - m; k > 0; k--)
			{
				_putchar(' ');
			}
			for (k = 0; k < m; k++)
			{
				_putchar('#');
			}
			if (m == size)
			{
				continue;
			}
			_putchar('\n');
		}
	}
	_putchar('\n');
}
