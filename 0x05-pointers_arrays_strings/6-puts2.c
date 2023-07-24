#include "main.h"
/**
 * puts2 - a function that prints every other character of a string,
 * starting with the first character
 * @str: string
 * Return: nothing
 */
void puts2(char *str)
{
	int length = 0;
	int k = 0;
	char *j = str;
	int i;

	while (*j != '\0')
	{
		j++;
		length++;
	}
	k = length - 1;
	for (i = 0 ; i <= k ; i++)
	{
		if (i % 2 == 0)
	{
		_putchar(str[i]);
	}
	}
	_putchar('\n');
}

