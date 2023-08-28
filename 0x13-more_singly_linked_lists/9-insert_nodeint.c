#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: pointer to the address of the head of the listint_t list.
 * @idx: index of the list where the new node should be added.
 * @n: integer to be included in the new node.
 *
 * Return: The address of the new node, or NULL if it failed
 * or if it is not possible to add the new node at index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		temp_node = *head;
		for (i = 0; i < idx - 1 && temp_node != NULL; i++)
			temp_node = temp_node->next;
		if (temp_node == NULL)
			return (NULL);
	}
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = temp_node->next;
		temp_node->next = new_node;
	}
	return (new_node);
}
