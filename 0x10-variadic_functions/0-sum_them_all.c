#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * sum_them_all - a function that returns the sum of all its parameters
 * @n: is the number of para passed to funct
 *
 * Return: 0 if n == 0 otherwise sum all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list fr;
	unsigned int i, sum = 0;

	va_start(fr, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(fr, unsigned int);
	}
	va_end(fr);

	return (sum);
}
