#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list,
 * and returns the head node's data (n).
 * @head: pointer to the address of the first node of the listint_t list.
 *
 * Return: If the linked list is empty - 0.
 * Otherwise - the head node's data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *temp_node;
	int count;

	if (*head == NULL)
		return (0);

	temp_node = *head;
	count = (*head)->n;
	*head = (*head)->next;
	free(temp_node);
	return (count);
}

