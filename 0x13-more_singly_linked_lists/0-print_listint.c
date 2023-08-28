#include "lists.h"
#include <stdio.h>

/**
 * print_listint - funct to print all element of a listin_t list
 * @h: pointer to the current node
 * Return: Total number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	}
	return (nodes);
}
