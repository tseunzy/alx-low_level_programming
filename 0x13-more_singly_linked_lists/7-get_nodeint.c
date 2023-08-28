#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: pointer to the first node of the listint_t list.
 * @index: index of the node, starting at 0.
 *
 * Return: If the node does not exist - NULL.
 * Otherwise - the nth node of the listint_t list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}

