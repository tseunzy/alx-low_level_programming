#include "lists.h"

/**
 * *add_nodeint_end - Adds a new node at the end of a listint_t list
 * @head: pointer to the address of the first node in the list
 * @n: integer value to be included in the new node
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *main_node, *temp_node;

	main_node = malloc(sizeof(listint_t));

	if (main_node == NULL)
		return (NULL);

	main_node->n = n;
	main_node->next = NULL;

	if (*head == NULL)
		*head = main_node;
	else
	{
		temp_node = *head;
		while (temp_node->next != NULL)
			temp_node = temp_node->next;
		temp_node->next = main_node;
	}
	return (main_node);
}
