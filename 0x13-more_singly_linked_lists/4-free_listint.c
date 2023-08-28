#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: pointer to the first node of the listint_t list
 */
void free_listint(listint_t *head)
{
	listint_t *temp_node;

	while (head != NULL)
	{
		temp_node = head;
		head = head->next;
		free(temp_node);
	}
}
