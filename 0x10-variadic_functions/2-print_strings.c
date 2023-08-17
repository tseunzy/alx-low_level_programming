
#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - a funct that prints strings, followed by a new line.
 * @separator: is the string to be printed between strings.
 * @n: is the num of strings passed to the funct
 * Return: If separator is NULL, don’t print it
 * If one of the string is NULL, print (nil) instead
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list sr;
	unsigned int i;
	char *str;

	va_start(sr, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(sr, char *);

		printf("%s", (str != NULL) ? str : "(nil)");

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(sr);
}
