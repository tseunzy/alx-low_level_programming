#include "lists.h"

/**
 * listint_len - funct to return the num of element
 * @h: pointer to the first node of the list
 * Return: number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
