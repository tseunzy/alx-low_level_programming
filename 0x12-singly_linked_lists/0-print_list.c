#include <stdio.h>
#include "lists.h"

/**
 * print_list - Outputs the elements of a linked list.
 * @h: Pointer to the start of the list_t list.
 *
 * Each element is printed in the format "[length] string", where
 * "length" is the length of the string and "string" is the content
 * of the string. If the string is NULL, it prints "[0] (nil)".
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		nodes++;
	}
	return (nodes);
}

