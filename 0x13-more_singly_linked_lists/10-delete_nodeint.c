#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index
 * @head: A pointer to the address of the head of the listint_t list.
 * @index: The index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *temp2;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	temp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (i < index - 1)
	{
		if (temp == NULL || temp->next == NULL)
			return (-1);
		temp = temp->next;
		i++;
	}

	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);

	return (1);
}
