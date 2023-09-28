#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: A pointer to the number in which to clear the bit.
 * @index: The index of the bit to clear, starting from 0.
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int msk;

	if (index >= (sizeof(*n) * 8) || n == NULL)
		return (-1);

	msk = ~(1 << index);

	*n &= msk;

	return (1);
}

