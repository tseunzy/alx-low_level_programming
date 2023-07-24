#include "main.h"

/**
 * rev_string - a function that reverses a string.
 * @s: string
 * Return: nothing
 */

void rev_string(char *s)
{
	char rev = s[0];
	int length = 0;
	int i;

	while (s[length] != '\0')
	length++;
	for (i = 0; i < length; i++)
	{
		length--;
		rev = s[i];
		s[i] = s[length];
		s[length] = rev;
	}
}

