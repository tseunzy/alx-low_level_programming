#include "main.h"
#include <unistd.h>

/**
 * print_alphabet_x10 - Entry point
 * Return:0
 */
void print_alphabet_x10(void)
{
	char num = '0';
	char alph;

	while (num <= 9)
	{
		alph = 'z';

		while (alph <= 'z')
		{
			_putchar(alph);
			alph++;
		}
		_putchar('\n');
		num++;
	}
}
