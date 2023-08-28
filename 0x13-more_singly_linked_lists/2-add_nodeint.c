#include "lists.h"

/**
 * add_nodeint - funct to add a new node at the begining
 * @head: pointer to the first node in the list
 * @n: integer to add at the begining
 * Return: Address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

