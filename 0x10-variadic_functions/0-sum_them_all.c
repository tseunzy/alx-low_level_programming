#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - a function that returns the sum of all its parameters
 * @n: is the number of para passed to funct
 *
 * Return: 0 if n == 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list fist;
	unsigned int sum = 0;

	va_start(fist, n);


	for (int i = 0; i < n; i++)
	{
		sum += va_arg(fist, int);
	}
	va_end(fist);

	return (sum);
}
