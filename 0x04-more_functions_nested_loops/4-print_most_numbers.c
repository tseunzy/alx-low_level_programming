#include "main.h"

/**
 * print_most_numbers - func that prints the numbers, from 0 to 9
 *
 * Return: Always 0
 */
void print_most_numbers(void)
{
	int m;

	for (m = '0'; m <= '9'; m++)
	{
		if (m != '2')
		{
			if (m != '4')
			{
				_putchar(m);
			}
		}
	}
	_putchar('\n');
}
