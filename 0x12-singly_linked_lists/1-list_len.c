#include <stdlib.h>
#include "lists.h"
/**
 * list_len - Counts the number of nodes in a linked list.
 * @h: Pointer to the first node of the list.
 * Description:
 * This function starts at the beginning of the list and traverses
 * through each node until it reaches the end, keeping a tally of
 * the number of nodes it has visited.
 * Return: The total number of nodes in the list.
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
