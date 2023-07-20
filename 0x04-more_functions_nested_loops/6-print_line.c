#include "main.h"
/**
 * print_line - a function that draws a straight line in the terminal.
 *
 * @n: Number of times the character _ should be printed
 */

void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}
	{

		int i;

		for (i = 0; i <= n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
