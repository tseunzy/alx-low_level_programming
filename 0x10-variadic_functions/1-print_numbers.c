#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - a funct that prints numbers, followed by a new line
 * @n: num of integer passed to the funct
 * @separator: is the string to be printed btw num
 * Return: If separator is NULL, don’t print it
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list fr;
	unsigned int i;

	va_start(fr, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(fr, int));

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(fr);
}
