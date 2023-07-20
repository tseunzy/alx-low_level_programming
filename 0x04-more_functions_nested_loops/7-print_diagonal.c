#include "main.h"

/**
 * print_diagonal - a function that draws a diagonal line on the termina
 *
 * @n: Number of times the character \ should be printed
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int m, k;

		for (m = 0; m < k; m++)
		{
			for (k = 0; k < n; k++)
			{
				if (k == m)
					_putchar('\\');
				else if (k < m)
					_putchar(' ');
			}
			_putchar('\n');
		}
	}
}
