#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the address of the head of the listint_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	for (; *head != NULL; *head = next)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
	}
	*head = prev;

	return (*head);
}

